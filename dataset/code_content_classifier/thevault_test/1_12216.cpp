static int ComparePathSegment(AZStd::string_view left, AZStd::string_view right, bool exactCaseCompare)
    {
        const size_t maxCharsToCompare = (AZStd::min)(left.size(), right.size());

        int charCompareResult = exactCaseCompare
            ? maxCharsToCompare ? strncmp(left.data(), right.data(), maxCharsToCompare) : 0
            : maxCharsToCompare ? azstrnicmp(left.data(), right.data(), maxCharsToCompare) : 0;
        return charCompareResult == 0
            ? static_cast<int>(aznumeric_cast<ptrdiff_t>(left.size()) - aznumeric_cast<ptrdiff_t>(right.size()))
            : charCompareResult;
    }