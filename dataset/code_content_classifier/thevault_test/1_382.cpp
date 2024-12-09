json::json Users::Invoices(const json::json& params, bool fHelp)
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

            /* Check for limit parameter. */
            uint32_t nLimit = 100;
            if(params.find("limit") != params.end())
                nLimit = std::stoul(params["limit"].get<std::string>());

            /* Check for status parameter. */
            std::string strStatus = "";
            if(params.find("status") != params.end())
                strStatus = params["status"].get<std::string>();

            /* Get the list of registers owned by this sig chain */
            std::vector<TAO::Register::Address> vAddresses;
            ListRegisters(hashGenesis, vAddresses);

            /* Get any registers that have been transferred to this user but not yet paid (claimed) */
            std::vector<std::tuple<TAO::Operation::Contract, uint32_t, uint256_t>> vUnclaimed;
            Users::get_unclaimed(hashGenesis, vUnclaimed);

            /* Add the unclaimed register addresses to the list */
            for(const auto& unclaimed : vUnclaimed)
                vAddresses.push_back(std::get<2>(unclaimed));

            /* For efficiency we can remove any addresses that are not read only registers */
            vAddresses.erase(std::remove_if(vAddresses.begin(), vAddresses.end(), 
                                            [](const TAO::Register::Address& address){return !address.IsReadonly();}), 
                                            vAddresses.end());

            /* Read all the registers to that they are sorted by creation time */
            std::vector<std::pair<TAO::Register::Address, TAO::Register::State>> vRegisters;
            GetRegisters(vAddresses, vRegisters);

            /* Add the register data to the response */
            uint32_t nTotal = 0;
            for(const auto& state : vRegisters)
            {
                /* The invoice JSON data */
                json::json invoice;

                /* Only include read only register type */
                if(state.second.nType != TAO::Register::REGISTER::READONLY)
                    continue;

                /* Deserialize the leading byte of the state data to check that it is an invoice */
                uint16_t type;
                state.second >> type;

                if(type != TAO::API::USER_TYPES::INVOICE)
                    continue;

                
                /* check status filter */
                if(!strStatus.empty())
                {
                    /* deserialize the invoice data */
                    invoice = Invoices::InvoiceToJSON(params, state.second, state.first);

                    /* Get the invoice status and skip if it doesn't match the filter */
                    if( invoice["status"].get<std::string>() != strStatus )
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

                /* deserialize the invoice data if we haven't already */
                if(invoice.empty())
                    invoice = Invoices::InvoiceToJSON(params, state.second, state.first);
            
                /* Add the invoice json to the response */
                ret.push_back(invoice);

            }

            return ret;
        }