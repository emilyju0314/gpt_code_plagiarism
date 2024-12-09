bool IsEqual(const uint8_t *aPrefix, uint8_t aPrefixLength) const
    {
        return (aPrefixLength == mPrefixLength) &&
               (Ip6::Prefix::MatchLength(GetPrefix(), aPrefix, Ip6::Prefix::SizeForLength(aPrefixLength)) >=
                mPrefixLength);
    }