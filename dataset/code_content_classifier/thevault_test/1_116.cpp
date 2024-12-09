void SetLinkQualityIn(uint8_t aRouterIndex, uint8_t aLinkQuality)
    {
        mRouteData[aRouterIndex] = (mRouteData[aRouterIndex] & ~kLinkQualityInMask) |
                                   ((aLinkQuality << kLinkQualityInOffset) & kLinkQualityInMask);
    }