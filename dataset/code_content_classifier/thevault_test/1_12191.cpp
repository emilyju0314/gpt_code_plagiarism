AZStd::string ToLower(AZStd::string_view inStr)
        {
            AZStd::string lowerStr = inStr;
            AZStd::to_lower(lowerStr.begin(), lowerStr.end());

            return lowerStr;
        }