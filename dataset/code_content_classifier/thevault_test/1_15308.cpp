const void* engine_ast::SDPSuperOpNode::getAuxData(engine_ast::Edge* auxEdge)
{
    NvDlaError e = NvDlaSuccess;
    void* data = NULL;
    SdpXengineToEdgeMapIterator xEdge;
    SDPSubEngineTypeEnum xN;
    NVDLA_UNUSED(e);

    // is auxEdge valid
    if (auxEdge == NULL)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Invalid auxEdge for node %s", name().c_str());
    }
    xEdge = findSdpAuxEdge(auxEdge);
    if ( xEdge == m_sdpXengineToAuxEdgeMap.end() )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Invalid auxEdge for node %s", name().c_str());
    }
    xN = SDPSubEngineTypeEnum(xEdge->first);
    data = const_cast<void*>(params().dlaData(xN).values);
fail:
    return data;
}