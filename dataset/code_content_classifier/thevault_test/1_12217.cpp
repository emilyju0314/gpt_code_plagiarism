inline size_t HashSegment(AZStd::string_view pathSegment, bool hashExactPath)
    {
        size_t hash = 14695981039346656037ULL;
        constexpr size_t fnvPrime = 1099511628211ULL;

        for (const char first : pathSegment)
        {
            hash ^= static_cast<size_t>(hashExactPath ? first : tolower(first));
            hash *= fnvPrime;
        }
        return hash;
    }