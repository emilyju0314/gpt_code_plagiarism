static bool validateLaneLinkInRange(LaneSectionContactPointKey aSectionContactPointKey,
                                    LaneSectionContactPointKey bSectionContactPointKey, LaneID fromLaneId,
                                    LaneID toLaneId, bool roadsOpposingDirections, LaneID toLaneIDsMin,
                                    LaneID toLaneIDsMax, std::vector<std::unique_ptr<LinkValidationError>>& errors)
{
    if (toLaneId == LaneID(0))
    {
        LaneLinkToCenterLaneError* error = new LaneLinkToCenterLaneError();
        error->aSectionContactPointKey_ = aSectionContactPointKey;
        error->bSectionContactPointKey_ = bSectionContactPointKey;
        error->fromLaneId_ = fromLaneId;
        errors.emplace_back(error);
        return false;
    }

    // If the two roads have the same direction (ie, one is the
    // successor of the other, and the other the predecessor of the
    // first one), then the two lanes must be on the same side of their
    // respective reference line.
    //
    // If the two roads have opposing directions (ie, they meet head to
    // head or tail to tail), then the two lanes must be on opposite
    // sides of their respective reference lines.
    if (fromLaneId.sameSide(toLaneId) == roadsOpposingDirections)
    {
        LaneLinkOpposingDirections* error = new LaneLinkOpposingDirections();
        error->aSectionContactPointKey_ = aSectionContactPointKey;
        error->bSectionContactPointKey_ = bSectionContactPointKey;
        error->aLaneId_ = fromLaneId;
        error->bLaneId_ = toLaneId;
        errors.emplace_back(error);
        return false;
    }

    if (toLaneId < toLaneIDsMin || toLaneId > toLaneIDsMax)
    {
        LaneLinkTargetOutOfRange* error = new LaneLinkTargetOutOfRange();
        error->aSectionContactPointKey_ = aSectionContactPointKey;
        error->bSectionContactPointKey_ = bSectionContactPointKey;
        error->aLaneId_ = fromLaneId;
        error->bLaneId_ = toLaneId;
        errors.emplace_back(error);
        return false;
    }

    return true;
}