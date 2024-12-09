void SetRouteCost(uint8_t aRouterIndex, uint8_t aRouteCost)
    {
        if (aRouterIndex & 1)
        {
            mRouteData[aRouterIndex + aRouterIndex / 2 + 1] = aRouteCost;
        }
        else
        {
            mRouteData[aRouterIndex + aRouterIndex / 2] =
                (mRouteData[aRouterIndex + aRouterIndex / 2] & ~kRouteCostMask) |
                ((aRouteCost >> kOddEntryOffset) & kRouteCostMask);
            mRouteData[aRouterIndex + aRouterIndex / 2 + 1] = static_cast<uint8_t>(
                (mRouteData[aRouterIndex + aRouterIndex / 2 + 1] & ~(kRouteCostMask << kOddEntryOffset)) |
                ((aRouteCost & kRouteCostMask) << kOddEntryOffset));
        }
    }