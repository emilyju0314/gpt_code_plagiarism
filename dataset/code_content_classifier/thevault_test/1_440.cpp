json::json Objects::List(const json::json& params, uint8_t nRegisterType, uint8_t nObjectType)
        {
            /* JSON return value. */
            json::json ret = json::json::array();

            /* Get the Genesis ID. */
            uint256_t hashGenesis = 0;

            /* Watch for destination genesis. If no specific genesis or username
             * have been provided then fall back to the active sigchain. */
            if(params.find("genesis") != params.end())
                hashGenesis.SetHex(params["genesis"].get<std::string>());

            /* Check for username. */
            else if(params.find("username") != params.end())
                hashGenesis = TAO::Ledger::SignatureChain::Genesis(params["username"].get<std::string>().c_str());

            /* Check for default sessions. */
            else if(!config::fMultiuser.load() && users->LoggedIn())
                hashGenesis = users->GetGenesis(0);
            else
                throw APIException(-111, "Missing genesis / username");

            /* Check for paged parameter. */
            uint32_t nPage = 0;
            if(params.find("page") != params.end())
                nPage = std::stoul(params["page"].get<std::string>());

            /* Check for username parameter. */
            uint32_t nLimit = 100;
            if(params.find("limit") != params.end())
                nLimit = std::stoul(params["limit"].get<std::string>());

            /* Get the list of registers owned by this sig chain */
            std::vector<TAO::Register::Address> vAddresses;
            ListRegisters(hashGenesis, vAddresses);

            /* Get list of tokenized assets owned by this sig chain */
            ListPartial(hashGenesis, vAddresses);
            if(vAddresses.size() == 0)
                throw APIException(-74, "No registers found");

            /* Read all the registers to that they are sorted by creation time */
            std::vector<std::pair<TAO::Register::Address, TAO::Register::State>> vRegisters;
            GetRegisters(vAddresses, vRegisters);

            /* We pass false for fLookupName if the requested type is a name of namesace object,
               as those are the edge case that do not have a Name object themselves */
            bool fLookupName = nObjectType != TAO::Register::OBJECTS::NAME && nObjectType != TAO::Register::OBJECTS::NAMESPACE;

            /* Add the register data to the response */
            uint32_t nTotal = 0;
            for(const auto& state : vRegisters)
            {
                /* Only include requested register type */
                if(state.second.nType != nRegisterType)
                    continue;

                /* Cast to an Object */
                TAO::Register::Object object(state.second);

                /* Handle for object registers. */
                if(object.nType == TAO::Register::REGISTER::OBJECT)
                {
                    /* parse object so that the data fields can be accessed */
                    if(!object.Parse())
                        throw APIException(-36, "Failed to parse object register");

                    /* Only included requested object types. */
                    if((object.Standard() & nObjectType) == 0)
                        continue;
                }

                /* Get the current page. */
                uint32_t nCurrentPage = (nTotal / nLimit) ;

                /* Increment the counter */
                ++nTotal;

                /* Check the paged data. */
                if(nCurrentPage < nPage)
                    continue;

                if(nCurrentPage > nPage)
                    break;

                if(nTotal - (nPage * nLimit) > nLimit)
                    break;

                /* Populate the response JSON */
                json::json json;
                json["created"]  = state.second.nCreated;
                json["modified"] = state.second.nModified;

                json::json data  =TAO::API::ObjectToJSON(params, object, state.first, fLookupName);

                /* Copy the data in to the response after the  */
                json.insert(data.begin(), data.end());

                /* Add this objects json to the response */
                ret.push_back(json);

            }

            return ret;
        }