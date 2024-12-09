uint8_t GetLinkQualityOut(uint8_t aRouterIndex) const
    {
        int offset = ((aRouterIndex & 1) ? kOddEntryOffset : 0);
        return (mRouteData[aRouterIndex + aRouterIndex / 2] & (kLinkQualityOutMask >> offset)) >>
               (kLinkQualityOutOffset - offset);
    }