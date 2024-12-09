std::string Names::RewriteURL(const std::string& strMethod, json::json& jsonParams)
        {
            /* The rewritten method name to return.  Default to the method name passed in */
            std::string strMethodRewritten = strMethod;

            /* support passing the name after the method e.g. get/name/myname */
            std::string strNameOrAddress;

            /* First check for /name/ */
            std::size_t nPos = strMethod.find("/name/");
            if(nPos != std::string::npos)
            {
                /* Edge case for /names/list/name/history/somename */
                if(strMethod == "list/name/history")
                    return strMethod;
                else if(strMethod.find("list/name/history/") != std::string::npos)
                {
                    strMethodRewritten = "list/name/history";

                    /* Get the name or address that comes after the list/name/history part */
                    strNameOrAddress = strMethod.substr(18); 
                }
                else
                {
                    /* get the method name from the incoming string */
                    strMethodRewritten = strMethod.substr(0, nPos+5);

                    /* Get the name or address that comes after the /name/ part */
                    strNameOrAddress = strMethod.substr(nPos +6);
                }
            }

            /* Next check for /namespace/ */
            nPos = strMethod.find("/namespace/");
            if(nPos != std::string::npos)
            {
                /* Edge case for /names/list/namespace/history/somename */
                if(strMethod == "list/namespace/history")
                    return strMethod;
                else if(strMethod.find("list/namespace/history/") != std::string::npos)
                {
                    strMethodRewritten = "list/namespace/history";

                    /* Get the name or address that comes after the list/name/history part */
                    strNameOrAddress = strMethod.substr(23); 
                }
                else
                {
                    /* get the method name from the incoming string */
                    strMethodRewritten = strMethod.substr(0, nPos+10);

                    /* Get the name or address that comes after the /namespace/ part */
                    strNameOrAddress = strMethod.substr(nPos +11);
                }
            }


            if(!strNameOrAddress.empty())
            {
                /* Edge case for claim/name/txid */
                if(strMethodRewritten == "claim/name" || strMethodRewritten == "claim/namespace")
                    jsonParams["txid"] = strNameOrAddress;
                /* Determine whether the name/address is a valid register address and set the name or address parameter accordingly */
                else if(IsRegisterAddress(strNameOrAddress) && strMethodRewritten == "get/name")
                    jsonParams["register_address"] = strNameOrAddress;
                else if(IsRegisterAddress(strNameOrAddress))
                    jsonParams["address"] = strNameOrAddress;
                else
                    jsonParams["name"] = strNameOrAddress;
            }       

            return strMethodRewritten;
        }