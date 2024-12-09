bool RequestModifier::MatchPattern(const char *signature, const char *pattern)
    const
{
    if (signature == 0) {
        return false;
    }

    const size_t signatureLength = strlen(signature);
    if (signatureLength < 2) {
        return false;
    }

    const size_t patternLength = strlen(pattern);
    if (pattern[0] == '*') {
        return (signatureLength > patternLength &&
            strncmp(&pattern[1], &signature[signatureLength-patternLength],
                patternLength-1) == 0);
    } else if (pattern[patternLength-1] == '*') {
        return (strncmp(pattern, &signature[1], patternLength-1) == 0);
    } else {
        return (patternLength == signatureLength-2 &&
            strncmp(pattern, &signature[1], patternLength) == 0);
    }
}