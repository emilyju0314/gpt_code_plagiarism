bool IsValid(void) const
    {
        return ((GetLength() >= sizeof(*this) - sizeof(NetworkDataTlv)) &&
                (GetLength() >= Ip6::Prefix::SizeForLength(mPrefixLength) + sizeof(*this) - sizeof(NetworkDataTlv)) &&
                (Ip6::Prefix::SizeForLength(mPrefixLength) <= sizeof(Ip6::Address)));
    }