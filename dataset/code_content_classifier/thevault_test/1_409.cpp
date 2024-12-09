bool TritiumMinter::FindStakeChange(const uint256_t& hashGenesis, const uint512_t hashLast)
        {
            /* Check for pending stake change request */
            bool fRemove = false;
            TAO::Ledger::StakeChange request;
            uint64_t nStake = account.get<uint64_t>("stake");
            uint64_t nBalance = account.get<uint64_t>("balance");

            try
            {
                if(!LLD::Local->ReadStakeChange(hashGenesis, request) || request.fProcessed)
                {
                    /* No stake change request to process */
                    fStakeChange = false;
                    stakeChange.SetNull();
                    return true;
                }
            }
            catch(const std::exception& e)
            {
                std::string msg(e.what());
                std::size_t nPos = msg.find("end of stream");
                if(nPos != std::string::npos)
                {
                    /* Attempts to read/deserialize old format for StakeChange will throw an end of stream exception. */
                    fRemove = true;
                    debug::log(0, FUNCTION, "Stake Minter: Obsolete format for stake change request...removing.");
                }
                else
                    throw; //rethrow exception if not end of stream

            }

            /* Verify stake change request is current version supported by minter */
            if(!fRemove && request.nVersion != 1)
            {
                fRemove = true;
                debug::log(0, FUNCTION, "Stake Minter: Stake change request is unsupported version...removing.");
            }

            /* Verify current hashGenesis matches requesting value */
            if(!fRemove && hashGenesis != request.hashGenesis)
            {
                fRemove = true;
                debug::log(0, FUNCTION, "Stake Minter: Stake change request hashGenesis mismatch...removing.");
            }

            /* Verify that no blocks have been staked since the change was requested */
            if(!fRemove && request.hashLast != hashLast)
            {
                fRemove = true;
                debug::log(0, FUNCTION, "Stake Minter: Stake change request is stale...removing.");
            }

            /* Check for expired stake change request */
            if(!fRemove && request.nExpires != 0 && request.nExpires < runtime::unifiedtimestamp())
            {
                fRemove = true;
                debug::log(1, FUNCTION, "Stake Minter: Stake change request has expired...removing.");
            }

            /* Validate the change request crypto signature */
            if(!fRemove)
            {
                /* Get the crypto register for the current user hashGenesis. */
                TAO::Register::Address hashCrypto = TAO::Register::Address(std::string("crypto"), hashGenesis, TAO::Register::Address::CRYPTO);
                TAO::Register::Object crypto;
                if(!LLD::Register->ReadState(hashCrypto, crypto))
                    return debug::error(FUNCTION, "Stake Minter: Missing crypto register");

                /* Parse the object. */
                if(!crypto.Parse())
                    return debug::error(FUNCTION, "Stake Minter: Failed to parse crypto register");

                /* Verify the signature on the stake change request */
                uint256_t hashPublic = crypto.get<uint256_t>("auth");
                if(hashPublic != 0) //no auth key disables check
                {
                    /* Get hash of public key and set to same type as crypto register hash for verification */
                    uint256_t hashCheck = LLC::SK256(request.vchPubKey);
                    hashCheck.SetType(hashPublic.GetType());

                    /* Check the public key to expected authorization key. */
                    if(hashCheck != hashPublic)
                    {
                        LLD::Local->EraseStakeChange(hashGenesis);
                        return debug::error(FUNCTION, "Stake Minter: Invalid public key on stake change request...removing");
                    }

                    /* Switch based on signature type. */
                    switch(hashPublic.GetType())
                    {
                        /* Support for the FALCON signature scheeme. */
                        case TAO::Ledger::SIGNATURE::FALCON:
                        {
                            /* Create the FL Key object. */
                            LLC::FLKey key;

                            /* Set the public key and verify. */
                            key.SetPubKey(request.vchPubKey);
                            if(!key.Verify(request.GetHash().GetBytes(), request.vchSig))
                            {
                                LLD::Local->EraseStakeChange(hashGenesis);
                                return debug::error(FUNCTION, "Stake Minter: Invalid signature on stake change request...removing");
                            }

                            break;
                        }

                        /* Support for the BRAINPOOL signature scheme. */
                        case TAO::Ledger::SIGNATURE::BRAINPOOL:
                        {
                            /* Create EC Key object. */
                            LLC::ECKey key = LLC::ECKey(LLC::BRAINPOOL_P512_T1, 64);

                            /* Set the public key and verify. */
                            key.SetPubKey(request.vchPubKey);
                            if(!key.Verify(request.GetHash().GetBytes(), request.vchSig))
                            {
                                LLD::Local->EraseStakeChange(hashGenesis);
                                return debug::error(FUNCTION, "Stake Minter: Invalid signature on stake change request...removing");
                            }

                            break;
                        }

                        default:
                        {
                            LLD::Local->EraseStakeChange(hashGenesis);
                            return debug::error(FUNCTION, "Stake Minter: Invalid signature type on stake change request...removing");
                        }
                    }
                }
            }

            /* Verify stake/unstake limits */
            if(!fRemove)
            {
                if(request.nAmount < 0 && (0 - request.nAmount) > nStake)
                {
                    debug::log(0, FUNCTION, "Stake Minter: Cannot unstake more than current stake, using current stake amount.");
                    request.nAmount = 0 - nStake;
                }
                else if(request.nAmount > 0 && request.nAmount > nBalance)
                {
                    debug::log(0, FUNCTION, "Stake Minter: Cannot add more than current balance to stake, using current balance.");
                    request.nAmount = nBalance;
                }
                else if(request.nAmount == 0)
                {
                    /* Remove request if no change to stake amount */
                    fRemove = true;
                }
            }

            if(fRemove)
            {
                fStakeChange = false;
                stakeChange.SetNull();

                if (!LLD::Local->EraseStakeChange(hashGenesis))
                    debug::log(1, FUNCTION, "Stake Minter: Failed to remove stake change request");

                return true;
            }

            /* Set the results into stake minter instance */
            fStakeChange = true;
            stakeChange = request;

            return true;
        }