void InsertMarkup(const AZStd::string& sourceBuffer, AZStd::string& targetBuffer)
    {
        targetBuffer = "<root>" + sourceBuffer + "</root>";

        AZStd::string::size_type pos = targetBuffer.find(">");
        while (pos != AZStd::string::npos)
        {
            ++pos;
            if (pos < targetBuffer.length())
            {
                AZStd::string::value_type nextChar = targetBuffer.at(pos);

                if (nextChar != '<')
                {
                    static const AZStd::string CharStartTag("<ch value=\"");
                    targetBuffer.insert(pos, CharStartTag);
                    pos += CharStartTag.length();

                    pos = targetBuffer.find("<", pos);

                    if (AZStd::string::npos != pos)
                    {
                        static const AZStd::string CharEndTag("\" />");
                        targetBuffer.insert(pos, CharEndTag);
                        pos += CharEndTag.length();
                    }
                }
            }

            pos = targetBuffer.find(">", pos);
        }

        // Newlines need to be escaped or the XML parser could toss them out
        targetBuffer = AZStd::regex_replace(targetBuffer, AZStd::regex("\n"), "\\n");
    }