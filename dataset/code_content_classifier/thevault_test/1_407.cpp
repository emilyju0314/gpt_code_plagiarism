bool TritiumMinter::FindTrustAccount(const uint256_t& hashGenesis)
        {

            /* Reset saved trust account data */
            account = TAO::Register::Object();

            /*
             * Every user account should have a corresponding trust account created with its first transaction.
             * Upon staking Genesis, that account is indexed into the register DB and is directly retrievable.
             * Pre-Genesis, we have to retrieve the name register to obtain the trust account address.
             *
             * If this process fails in any way, the user account has no trust account available and cannot stake.
             * This is logged as an error and the stake minter should be suspended pending stop/shutdown.
             */

            if(LLD::Register->HasTrust(hashGenesis))
            {
                fGenesis = false;

                /* Staking Trust for trust account */

                /* Retrieve the trust account register */
                TAO::Register::Object reg;
                if(!LLD::Register->ReadTrust(hashGenesis, reg))
                   return debug::error(FUNCTION, "Stake Minter unable to retrieve trust account.");

                if(!reg.Parse())
                    return debug::error(FUNCTION, "Stake Minter unable to parse trust account register.");

                /* Found valid trust account register. Save for minter use. */
                account = reg;

                return true;
            }
            else
            {
                fGenesis = true;

                /* Staking Genesis for trust account. Trust account is not indexed, need to use trust account address. */
                uint256_t hashAddress = TAO::Register::Address(std::string("trust"), hashGenesis, TAO::Register::Address::TRUST);

                /* Retrieve the trust account */
                TAO::Register::Object reg;
                if(!LLD::Register->ReadState(hashAddress, reg))
                    return debug::error(FUNCTION, "Stake Minter unable to retrieve trust account for Genesis.");

                /* Verify we have trust account register for the user account */
                if(!reg.Parse())
                    return debug::error(FUNCTION, "Stake Minter unable to parse trust account register for Genesis.");

                if(reg.Standard() != TAO::Register::OBJECTS::TRUST)
                    return debug::error(FUNCTION, "Invalid trust account register.");

                /* Validate that this is a new trust account staking Genesis */

                /* Check that there is no stake. */
                if(reg.get<uint64_t>("stake") != 0)
                    return debug::error(FUNCTION, "Cannot create Genesis with already existing stake");

                /* Check that there is no trust. */
                if(reg.get<uint64_t>("trust") !=
                ((config::fTestNet.load() && config::GetBoolArg("-trustboost")) ? TAO::Ledger::ONE_YEAR : 0))
                    return debug::error(FUNCTION, "Cannot create Genesis with already existing trust");

                /* Found valid trust account register. Save for minter use. */
                account = reg;
            }

            return true;
        }