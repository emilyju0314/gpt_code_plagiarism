uint8_t GetLinkQualityIn(uint8_t aRouterIndex) const
    {
        int offset = ((aRouterIndex & 1) ? kOddEntryOffset : 0);
        return (mRouteData[aRouterIndex + aRouterIndex / 2] & (kLinkQualityInMask >> offset)) >>
               (kLinkQualityInOffset - offset);
    }