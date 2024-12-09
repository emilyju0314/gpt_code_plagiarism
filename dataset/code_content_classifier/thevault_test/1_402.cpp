std::string Users::RewriteURL(const std::string& strMethod, json::json& jsonParams)
        {
            std::string strMethodRewritten = strMethod;
            std::string strNameOrAddress;


            if(strMethod.find("user/")          != std::string::npos
            || strMethod.find("recovery/")      != std::string::npos
            || strMethod.find("transactions/")  != std::string::npos
            || strMethod.find("notifications/") != std::string::npos
            || strMethod.find("assets/")        != std::string::npos
            || strMethod.find("accounts/")      != std::string::npos
            || strMethod.find("items/")         != std::string::npos
            || strMethod.find("tokens/")        != std::string::npos
            || strMethod.find("names/")         != std::string::npos
            || strMethod.find("namespaces/")    != std::string::npos)
            {
                /* support passing the username after a list method e.g. list/assets/myusername */
                size_t nPos = strMethod.find_last_of("/");

                if(nPos != std::string::npos)
                {
                    /* get the method name from the incoming string */
                    strMethodRewritten = strMethod.substr(0, nPos);

                    /* Get the name or address that comes after the /item/ part */
                    strNameOrAddress = strMethod.substr(nPos + 1);

                    /* Determine whether the name/address is a valid register address and set the name or address parameter accordingly */
                    if(IsRegisterAddress(strNameOrAddress))
                        jsonParams["genesis"] = strNameOrAddress;
                    else
                        jsonParams["username"] = strNameOrAddress;
                }
            }

            return strMethodRewritten;
        }