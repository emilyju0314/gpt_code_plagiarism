bool ListRegisters(const uint256_t& hashGenesis, std::vector<TAO::Register::Address>& vRegisters)
        {
            /* LRU register cache by genesis hash.  This caches the vector of register addresses along with the last txid of the
               sig chain, so that we can determine whether any new transactions have been added, invalidating the cache.  */
            static LLD::TemplateLRU<uint256_t, std::pair<uint512_t, std::vector<TAO::Register::Address>>> cache(10);

            /* Get the last transaction. */
            uint512_t hashLast = 0;

            /* Get the last transaction for this genesis.  NOTE that we include the mempool here as there may be registers that
               have been created recently but not yet included in a block*/
            if(!LLD::Ledger->ReadLast(hashGenesis, hashLast, TAO::Ledger::FLAGS::MEMPOOL))
                return false;

            /* Check the cache to see if we have already cached the registers for this sig chain and it is still valid. */
            if(cache.Has(hashGenesis))
            {
                /* The cached register list */
                std::pair<uint512_t, std::vector<TAO::Register::Address>> cacheEntry;

                /* Retrieve the cached register list from the LRU cache */
                cache.Get(hashGenesis, cacheEntry);

                /* Check that the hashlast hasn't changed */
                if(cacheEntry.first == hashLast)
                {
                    /* Poplate vector to return */
                    vRegisters = cacheEntry.second;

                    return true;
                }

            }

            /* Keep a running list of owned and transferred registers. We use a set to store these registers because
             * we are going to be checking them frequently to see if a hash is already in the container,
             * and a set offers us near linear search time
             */
            std::unordered_set<uint256_t> vTransferred;
            std::unordered_set<uint256_t> vOwnedRegisters;

            /* The previous hash in the chain */
            uint512_t hashPrev = hashLast;

            /* Loop until genesis. */
            while(hashPrev != 0)
            {
                /* Get the transaction from disk. */
                TAO::Ledger::Transaction tx;
                if(!LLD::Ledger->ReadTx(hashPrev, tx, TAO::Ledger::FLAGS::MEMPOOL))
                    throw APIException(-108, "Failed to read transaction");

                /* Set the next last. */
                hashPrev = !tx.IsFirst() ? tx.hashPrevTx : 0;

                /* Iterate through all contracts. */
                for(uint32_t nContract = 0; nContract < tx.Size(); ++nContract)
                {
                    /* Get the contract output. */
                    const TAO::Operation::Contract& contract = tx[nContract];

                    /* Seek to start of the operation stream in case this a transaction from mempool that has already been read*/
                    contract.Reset(TAO::Operation::Contract::OPERATIONS);

                    /* Deserialize the OP. */
                    uint8_t nOP = 0;
                    contract >> nOP;

                    /* Check the current opcode. */
                    switch(nOP)
                    {
                        /* Condition that allows a validation to occur. */
                        case TAO::Operation::OP::CONDITION:
                        {
                            /* Condition has no parameters. */
                            contract >> nOP;

                            break;
                        }


                        /* Validate a previous contract's conditions */
                        case TAO::Operation::OP::VALIDATE:
                        {
                            /* Skip over validate. */
                            contract.Seek(68);

                            /* Get next OP. */
                            contract >> nOP;

                            break;
                        }
                    }

                    /* Check the current opcode. */
                    switch(nOP)
                    {

                        /* These are the register-based operations that prove ownership if encountered before a transfer*/
                        case TAO::Operation::OP::WRITE:
                        case TAO::Operation::OP::APPEND:
                        case TAO::Operation::OP::CREATE:
                        case TAO::Operation::OP::DEBIT:
                        {
                            /* Extract the address from the contract. */
                            TAO::Register::Address hashAddress;
                            contract >> hashAddress;

                            /* for these operations, if the address is NOT in the transferred list
                               then we know that we must currently own this register */
                           if(vTransferred.find(hashAddress)    == vTransferred.end()
                           && vOwnedRegisters.find(hashAddress) == vOwnedRegisters.end())
                           {
                               /* Add to owned set. */
                               vOwnedRegisters.insert(hashAddress);

                               /* Add to return vector. */
                               vRegisters.push_back(hashAddress);
                           }

                            break;
                        }


                        /* Check for credits here. */
                        case TAO::Operation::OP::CREDIT:
                        {
                            /* Seek past irrelevant data. */
                            contract.Seek(68);

                            /* The account that is being credited. */
                            TAO::Register::Address hashAddress;
                            contract >> hashAddress;

                            /* If we find a credit before a transfer transaction for this register then
                               we can know for certain that we must own it */
                           if(vTransferred.find(hashAddress)    == vTransferred.end()
                           && vOwnedRegisters.find(hashAddress) == vOwnedRegisters.end())
                           {
                               /* Add to owned set. */
                               vOwnedRegisters.insert(hashAddress);

                               /* Add to return vector. */
                               vRegisters.push_back(hashAddress);
                           }

                            break;

                        }


                        /* Check for a transfer here. */
                        case TAO::Operation::OP::TRANSFER:
                        {
                            /* Extract the address from the contract. */
                            TAO::Register::Address hashAddress;
                            contract >> hashAddress;

                            /* Read the register transfer recipient. */
                            TAO::Register::Address hashTransfer;
                            contract >> hashTransfer;

                            /* Read the force transfer flag */
                            uint8_t nType = 0;
                            contract >> nType;

                            /* If we have transferred to a token that we own then we ignore the transfer as we still
                               technically own the register */
                            if(nType == TAO::Operation::TRANSFER::FORCE)
                            {
                                TAO::Register::Object newOwner;
                                if(!LLD::Register->ReadState(hashTransfer, newOwner))
                                    throw APIException(-153, "Transfer recipient object not found");

                                if(newOwner.hashOwner == hashGenesis)
                                    break;
                            }
                            else
                            {
                                /* Retrieve the object so we can see whether it has been claimed or not */
                                TAO::Register::Object object;
                                if(!LLD::Register->ReadState(hashAddress, object, TAO::Ledger::FLAGS::MEMPOOL))
                                    throw APIException(-104, "Object not found");

                                /* If we are transferring to someone else but it has not yet been claimed then we ignore the
                                   transfer and still show it as ours */
                                if(object.hashOwner.GetType() == TAO::Ledger::GENESIS::SYSTEM)
                                    break;
                            }


                            /* If we find a TRANSFER then we can know for certain that we no longer own it */
                            if(vTransferred.find(hashAddress)    == vTransferred.end())
                                vTransferred.insert(hashAddress);

                            break;
                        }


                        /* Check for claims here. */
                        case TAO::Operation::OP::CLAIM:
                        {
                            /* Seek past irrelevant data. */
                            contract.Seek(68);

                            /* Extract the address from the contract. */
                            TAO::Register::Address hashAddress;
                            contract >> hashAddress;

                            /* If we find a CLAIM transaction before a TRANSFER, then we know that we must currently own this register */
                            if(vTransferred.find(hashAddress)    == vTransferred.end()
                            && vOwnedRegisters.find(hashAddress) == vOwnedRegisters.end())
                            {
                                /* Add to owned set. */
                                vOwnedRegisters.insert(hashAddress);

                                /* Add to return vector. */
                                vRegisters.push_back(hashAddress);
                            }

                            break;
                        }

                        default:
                            continue;
                    }
                }
            }

            /* Add the register list to the LRU cache */
            cache.Put(hashGenesis, std::make_pair(hashLast, vRegisters));

            return true;
        }