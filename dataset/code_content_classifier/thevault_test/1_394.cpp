uint8_t GetDecimals(const TAO::Register::Object& object)
        {
            /* Declare the nDecimals to return */
            uint8_t nDecimals = 0;

            /* Get the object standard. */
            uint8_t nStandard = object.Standard();

            /* Check the object standard. */
            switch(nStandard)
            {
                case TAO::Register::OBJECTS::TOKEN:
                {
                    nDecimals = object.get<uint8_t>("decimals");
                    break;
                }

                case TAO::Register::OBJECTS::TRUST:
                {
                    nDecimals = TAO::Ledger::NXS_DIGITS; // NXS token default digits
                    break;
                }

                case TAO::Register::OBJECTS::ACCOUNT:
                {
                    /* If debiting an account we need to look at the token definition in order to get the digits. */
                    TAO::Register::Address nIdentifier = object.get<uint256_t>("token");

                    /* Edge case for NXS token which has identifier 0, so no look up needed */
                    if(nIdentifier == 0)
                        nDecimals = TAO::Ledger::NXS_DIGITS;
                    else
                    {

                        TAO::Register::Object token;
                        if(!LLD::Register->ReadState(nIdentifier, token, TAO::Ledger::FLAGS::MEMPOOL))
                            throw APIException(-125, "Token not found");

                        /* Parse the object register. */
                        if(!token.Parse())
                            throw APIException(-14, "Object failed to parse");

                        nDecimals = token.get<uint8_t>("decimals");
                    }
                    break;
                }

                default:
                {
                    throw APIException(-124, "Unknown token / account.");
                }

            }

            return nDecimals;
        }