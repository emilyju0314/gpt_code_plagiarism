std::vector<surface::SurfaceFormat> engine_ast::SDPSuperOpNode::suggestAuxSurfaceFormats(engine_ast::Edge* auxEdge)
{
    NvDlaError e = NvDlaSuccess;
    NVDLA_UNUSED(e);
    std::vector<surface::SurfaceFormat> supportedAuxSFs;
    std::vector<surface::SurfaceFormat> suggestedAuxSFs;
    SdpXengineToEdgeMapIterator xEdge;
    SDPSubEngineTypeEnum xN;
    TensorType ttN;
    //surface::SurfacePrecision compPrec = graph()->profile()->computePrecision();

    // is auxEdge valid
    if (auxEdge == NULL)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Invalid auxEdge for node %s, required to suggest aux surface formats", name().c_str());
    }
    xEdge = findSdpAuxEdge(auxEdge);
    if ( xEdge == m_sdpXengineToAuxEdgeMap.end() )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Invalid auxEdge for node %s, required to suggest aux surface formats", name().c_str());
    }

    // Get tensortype from AuxEdge subengine type
    xN = SDPSubEngineTypeEnum(xEdge->first);
    ttN = params().auxDataType(xN);
    if ( auxEdge->originalTensor()->getTensorType() != ttN )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Invalid auxEdge for node %s, tensor types dont match", name().c_str());
    }

    // Get surface formats for the aux data on subengine
    suggestedAuxSFs = params().auxSurfaceFormats(xN);

    if (suggestedAuxSFs.size() == 0)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "No supported aux surface formats for %s", name().c_str());
    }

fail:
    return suggestedAuxSFs;
}