json::json System::LispEIDs(const json::json& params, bool fHelp)
        {
            json::json jsonEIDs = json::json::array();

            std::map<std::string, LLP::EID> mapEIDs = LLP::GetEIDs();
            if(mapEIDs.size() > 0)
            {
                for(const auto& eid : mapEIDs)
                {
                    json::json jsonEID;

                    jsonEID["instance-id"] = eid.second.strInstanceID;
                    jsonEID["eid"] = eid.second.strAddress;

                    json::json jsonRLOCs = json::json::array();

                    for(const auto& rloc : eid.second.vRLOCs)
                    {
                        json::json jsonRLOC;

                        jsonRLOC["interface"] = rloc.strInterface;
                        jsonRLOC["rloc-name"] = rloc.strRLOCName;
                        jsonRLOC["rloc"] = rloc.strTranslatedRLOC;

                        jsonRLOCs.push_back(jsonRLOC);
                    }

                    jsonEID["rlocs"] = jsonRLOCs;

                    jsonEIDs.push_back(jsonEID);
                }
            }

            return jsonEIDs;

        }