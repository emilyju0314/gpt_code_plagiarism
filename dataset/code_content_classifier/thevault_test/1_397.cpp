bool ListTokenizedObjects(const TAO::Register::Address& hashToken,
                                  std::vector<TAO::Register::Address>& vObjects)
        {
            /* There is no index of the assets owned by a token.  Therefore, to determine which assets the token owns, we can scan
               through the events for the token itself to find all object transfers where the new owner is the token. */

            /* Transaction for the event. */
            TAO::Ledger::Transaction tx;

            /* Iterate all events in the sig chain */
            uint32_t nSequence = 0;
            while(LLD::Ledger->ReadEvent(hashToken, nSequence, tx))
            {
                /* Loop through transaction contracts. */
                uint32_t nContracts = tx.Size();
                for(uint32_t nContract = 0; nContract < nContracts; ++nContract)
                {
                    /* Reset the op stream */
                    tx[nContract].Reset();

                    /* The operation */
                    uint8_t nOp;
                    tx[nContract] >> nOp;

                    if(nOp == TAO::Operation::OP::TRANSFER)
                    {
                        /* The register address being transferred */
                        TAO::Register::Address hashRegister;
                        tx[nContract] >> hashRegister;

                        /* Get the new owner hash */
                        TAO::Register::Address hashTo;
                        tx[nContract] >> hashTo;

                        /* Read the force transfer flag */
                        uint8_t nType = 0;
                        tx[nContract] >> nType;

                        /* Ensure this was a forced transfer (which tokenized asset transfers must be) */
                        if(nType != TAO::Operation::TRANSFER::FORCE)
                            continue;

                        /* Check that the recipient of the transfer is the token */
                        if(hashToken != hashTo)
                            continue;

                        vObjects.push_back(hashRegister);
                    }

                    else
                        continue;
                }

                /* Iterate the sequence id forward. */
                ++nSequence;
            }

            /* Return true if we found any objects owned by the token */
            return vObjects.size() > 0;
        }