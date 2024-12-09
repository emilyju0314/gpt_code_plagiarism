static void GetListOfMacroDefinitionNames( 
            const AZStd::string& stringWithArguments, AZStd::vector<AZStd::string>& macroDefinitionNames)
        {
            const AZStd::regex macroRegex(R"(-D\s*(\w+))", AZStd::regex::ECMAScript);

            AZStd::string hayStack(stringWithArguments);
            AZStd::smatch match;
            while (AZStd::regex_search(hayStack.c_str(), match, macroRegex))
            {
                // First pattern is always the entire string
                for (unsigned i = 1; i < match.size(); ++i)
                {
                    if (match[i].matched)
                    {
                        AZStd::string macroToAdd(match[i].str().c_str());
                        const bool isPresent = AZStd::any_of(AZ_BEGIN_END(macroDefinitionNames),
                            [&](AZStd::string_view macroName) -> bool
                            {
                                return macroToAdd == macroName;
                            }
                        );
                        if (isPresent)
                        {
                            continue;
                        }
                        macroDefinitionNames.push_back(macroToAdd);
                    }
                }
                hayStack = match.suffix();
            }
        }