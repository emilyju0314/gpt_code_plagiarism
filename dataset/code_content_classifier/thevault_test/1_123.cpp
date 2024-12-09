void SetLinkQualityOut(uint8_t aRouterIndex, uint8_t aLinkQuality)
    {
        int offset = ((aRouterIndex & 1) ? kOddEntryOffset : 0);
        mRouteData[aRouterIndex + aRouterIndex / 2] =
            (mRouteData[aRouterIndex + aRouterIndex / 2] & ~(kLinkQualityOutMask >> offset)) |
            ((aLinkQuality << (kLinkQualityOutOffset - offset)) & (kLinkQualityOutMask >> offset));
    }