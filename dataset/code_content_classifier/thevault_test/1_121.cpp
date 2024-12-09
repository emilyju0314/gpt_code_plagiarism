void SetLinkQualityIn(uint8_t aRouterIndex, uint8_t aLinkQuality)
    {
        int offset = ((aRouterIndex & 1) ? kOddEntryOffset : 0);
        mRouteData[aRouterIndex + aRouterIndex / 2] =
            (mRouteData[aRouterIndex + aRouterIndex / 2] & ~(kLinkQualityInMask >> offset)) |
            ((aLinkQuality << (kLinkQualityInOffset - offset)) & (kLinkQualityInMask >> offset));
    }