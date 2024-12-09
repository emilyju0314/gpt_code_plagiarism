static void GetListOfMacroDefinitions(
            const AZStd::string& stringWithArguments, AZStd::vector<AZStd::string>& macroDefinitions)
        {
            const AZStd::regex macroRegex(R"(-D\s*(\w+)(=\w+)?)", AZStd::regex::ECMAScript);

            AZStd::string hayStack(stringWithArguments);
            AZStd::smatch match;
            while (AZStd::regex_search(hayStack.c_str(), match, macroRegex))
            {
                if (match.size() > 1)
                {
                    AZStd::string macro(match[1].str().c_str());
                    if (match.size() > 2)
                    {
                        macro += match[2].str().c_str();
                    }
                    macroDefinitions.push_back(macro);
                }
                hayStack = match.suffix();
            }
        }