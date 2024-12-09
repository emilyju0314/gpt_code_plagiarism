void SetLinkQualityOut(uint8_t aRouterIndex, uint8_t aLinkQuality)
    {
        mRouteData[aRouterIndex] = (mRouteData[aRouterIndex] & ~kLinkQualityOutMask) |
                                   ((aLinkQuality << kLinkQualityOutOffset) & kLinkQualityOutMask);
    }