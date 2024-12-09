uint8_t GetRouteCost(uint8_t aRouterIndex) const
    {
        if (aRouterIndex & 1)
        {
            return mRouteData[aRouterIndex + aRouterIndex / 2 + 1];
        }
        else
        {
            return static_cast<uint8_t>((mRouteData[aRouterIndex + aRouterIndex / 2] & kRouteCostMask)
                                        << kOddEntryOffset) |
                   ((mRouteData[aRouterIndex + aRouterIndex / 2 + 1] &
                     static_cast<uint8_t>(kRouteCostMask << kOddEntryOffset)) >>
                    kOddEntryOffset);
        }
    }