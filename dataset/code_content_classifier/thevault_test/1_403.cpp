bool HasCondition(const TAO::Operation::Contract& contract, const TAO::Operation::Contract& condition)
        {
            bool fHasCondition = false;

            /* Reset the contract conditions stream */
            contract.Reset(TAO::Operation::Contract::CONDITIONS);

            /* search the contract to find the first instance of the same byte */
            while(!contract.End(TAO::Operation::Contract::CONDITIONS) && !fHasCondition)
            {
                /* Reset the conditions stream on the expiration as we are starting a new comparison */
                condition.Reset(TAO::Operation::Contract::CONDITIONS);

                /* Get byte from the expiration condition */
                uint8_t byte;
                condition >= byte;
                
                /* Get byte to compare from the comparison contract */
                uint8_t compare;
                contract >= compare;

                /* Cache the stream position so we can reset to here if a match is not found */
                uint64_t nPos = contract.Position(TAO::Operation::Contract::CONDITIONS);

                /* If the byte matches then start the rest of the comparison */
                if(compare == byte)
                { 
                    while(!condition.End(TAO::Operation::Contract::CONDITIONS) && !contract.End(TAO::Operation::Contract::CONDITIONS))
                    {
                        condition >= byte;
                        contract >= compare;

                        /* Check the bytes match.  If not then we can break out of this comparison */
                        if(byte != compare)
                            break;

                        /* If this is an OP::TYPES then we need to skip both stream ahead by the number of bytes, as this is caller
                           specific data and won't match - we are only comparing the operations and logic, not the data */
                        switch(byte)
                        {
                            case OP::TYPES::UINT8_T :
                            {
                                condition.Seek(1, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(1, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT16_T :
                            {
                                condition.Seek(2, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(2, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT32_T :
                            {
                                condition.Seek(4, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(4, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT64_T :
                            {
                                condition.Seek(8, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(8, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT256_T :
                            {
                                condition.Seek(32, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(32, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT512_T :
                            {
                                condition.Seek(64, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(64, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::UINT1024_T :
                            {
                                condition.Seek(128, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(128, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                            case OP::TYPES::BYTES :
                            {
                                std::vector<uint8_t> bytes;
                                condition >= bytes;
                                contract >= bytes;
                                break;
                            }
                            case OP::TYPES::STRING :
                            {
                                std::string string;
                                condition >= string;
                                contract >= string;
                                break;
                            }
                            case OP::SUBDATA :
                            {
                                /* OP::SUBDATA has two uint16_t's for the start pos and length, so skip 4 bytes */
                                condition.Seek(4, TAO::Operation::Contract::CONDITIONS);
                                contract.Seek(4, TAO::Operation::Contract::CONDITIONS);
                                break;
                            }
                        }
                    }

                    /* If we got to the end of the expiration contract without breaking out then we must have a match */
                    if(condition.End(TAO::Operation::Contract::CONDITIONS))
                        fHasCondition = true;
                }

                /* If we didn't find a condition at this point, then seek to the point that we last checked and continue checking */
                if(!fHasCondition)
                    contract.Seek(nPos, TAO::Operation::Contract::CONDITIONS, STREAM::BEGIN);
            }


            return fHasCondition;
        }