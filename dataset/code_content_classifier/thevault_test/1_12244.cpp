bool CommandLine::ExtractNextParam(const AZStd::string& paramString, AZStd::string& outParamName, AZStd::string& outParamValue, size_t* inOutStartOffset)
    {
        outParamName.clear();
        outParamValue.clear();

        // check if we already reached the end of the string
        size_t offset = *inOutStartOffset;
        if (offset >= paramString.size())
        {
            return false;
        }

        // filter out the next parameter
        AZStd::string::const_iterator iterator = paramString.begin() + offset;
        size_t  paramNameStart      = InvalidIndex;
        size_t  paramValueStart     = InvalidIndex;
        bool    readingParamName    = false;
        bool    readingParamValue   = false;
        bool    foundNextParam      = false;
        bool    insideQuotes        = false;
        bool    prevCharWasSpace    = false;
        int32   bracketDepth        = 0;

        const char bracketOpen('{');
        const char bracketClose('}');

        while (foundNextParam == false)
        {
            // check if we reached the end now
            if (offset >= paramString.size())
            {
                *inOutStartOffset = offset;

                // if we were reading a parameter value
                if (readingParamValue)
                {
                    outParamValue = AZStd::string(&paramString[paramValueStart], offset - paramValueStart);
                    readingParamValue = false;
                    AzFramework::StringFunc::TrimWhiteSpace(outParamValue, false /* leading */, true /* trailing */);
                    AzFramework::StringFunc::Strip(outParamValue, bracketClose, true /* case sensitive */, false /* beginning */, true /* ending */);
                    AzFramework::StringFunc::Strip(outParamValue, bracketOpen, true /* case sensitive */, true /* beginning */, false /* ending */);
                    AzFramework::StringFunc::Strip(outParamValue, MCore::CharacterConstants::doubleQuote, true /* case sensitive */, true /* beginning */, true /* ending */);
                }

                return true;
            }

            // get the current character and check if it was a space or not
            char curChar = *iterator;
            if (offset > 0)
            {
                char prevChar = *(iterator - 1);

                prevCharWasSpace = (prevChar == MCore::CharacterConstants::space) || (prevChar == MCore::CharacterConstants::tab);
            }
            else
            {
                prevCharWasSpace = false;
            }

            // toggle inside quotes flag
            if (curChar == MCore::CharacterConstants::doubleQuote)
            {
                insideQuotes ^= true;
            }
            else if (curChar == bracketOpen)
            {
                bracketDepth++;
            }
            else if (curChar == bracketClose)
            {
                bracketDepth--;
            }

            // if it's the start of a parameter
            if (curChar == MCore::CharacterConstants::dash && !insideQuotes && !readingParamValue && outParamName.empty() && bracketDepth == 0)
            {
                paramNameStart = offset;
                readingParamName = true;
            }

            // if we found a parameter name
            if ((curChar == MCore::CharacterConstants::space || curChar == MCore::CharacterConstants::tab) && readingParamName)
            {
                outParamName = AZStd::string(&paramString[paramNameStart + 1], offset - paramNameStart - 1);
                readingParamName = false;
            }

            // detect the start of the parameter value
            if (!readingParamName && !readingParamValue && curChar != MCore::CharacterConstants::space && curChar != MCore::CharacterConstants::tab)
            {
                readingParamValue = true;
                paramValueStart = offset;
            }

            // the end of a value
            if (curChar == MCore::CharacterConstants::dash && insideQuotes == false && readingParamValue && !readingParamName && paramValueStart != offset && prevCharWasSpace && bracketDepth == 0)
            {
                outParamValue = AZStd::string(&paramString[paramValueStart], offset - paramValueStart);
                readingParamValue = false;
                *inOutStartOffset = offset;
                AzFramework::StringFunc::TrimWhiteSpace(outParamValue, false /* leading */, true /* trailing */);
                AzFramework::StringFunc::Strip(outParamValue, bracketClose, true /* case sensitive */, false /* beginning */, true /* ending */);
                AzFramework::StringFunc::Strip(outParamValue, bracketOpen, true /* case sensitive */, true /* beginning */, false /* ending */);
                AzFramework::StringFunc::Strip(outParamValue, MCore::CharacterConstants::doubleQuote, true /* case sensitive */, true /* beginning */, true /* ending */);
                return true;
            }

            // go to the next character
            ++offset;
            ++iterator;
        }

        return false;
    }