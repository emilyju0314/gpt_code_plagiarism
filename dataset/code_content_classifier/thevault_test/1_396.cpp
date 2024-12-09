bool ListPartial(const uint256_t& hashGenesis, std::vector<TAO::Register::Address>& vRegisters)
        {
            /* Find all token accounts owned by the caller */
            std::vector<TAO::Register::Address> vAccounts;
            ListAccounts(hashGenesis, vAccounts, true, false);

            for(const auto& hashAccount : vAccounts)
            {
                /* Make sure it is an account or the token itself (in case not all supply has been distributed)*/
                if(!hashAccount.IsAccount() && !hashAccount.IsToken())
                    continue;

                /* Get the account from the register DB. */
                TAO::Register::Object object;
                if(!LLD::Register->ReadState(hashAccount, object, TAO::Ledger::FLAGS::MEMPOOL))
                    throw APIException(-13, "Account not found");

                /* Check that this is a non-standard object type so that we can parse it and check the type*/
                if(object.nType != TAO::Register::REGISTER::OBJECT)
                    continue;

                /* parse object so that the data fields can be accessed */
                if(!object.Parse())
                    throw APIException(-36, "Failed to parse object register");

                /* Check that this is an account or token */
                if(object.Base() != TAO::Register::OBJECTS::ACCOUNT)
                    continue;

                /* Get the token*/
                TAO::Register::Address hashToken = object.get<uint256_t>("token") ;

                /* NXS can't be used to tokenize an asset so if this is a NXS account we can skip it */
                if(hashToken == 0)
                    continue;

                /* Get all objects owned by this token */
                std::vector<TAO::Register::Address> vTokenizedObjects;
                ListTokenizedObjects(hashToken, vTokenizedObjects);

                /* Add them to the list if they are not already in there */
                for(const auto& address : vTokenizedObjects)
                {
                    if(std::find(vRegisters.begin(), vRegisters.end(), address) == vRegisters.end())
                        vRegisters.push_back(address);
                }
            }

            return vRegisters.size() > 0;
        }