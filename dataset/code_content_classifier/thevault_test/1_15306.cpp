NvDlaError engine_ast::SDPSuperOpNode::auxEdgeBySubEngine(SDPSubEngineType xN, engine_ast::Edge **ret_edge)
{
    NvDlaError e = NvDlaSuccess;

    SdpXengineToEdgeMapIterator xEdgeElem = m_sdpXengineToAuxEdgeMap.find(xN.e());
    if (xEdgeElem == m_sdpXengineToAuxEdgeMap.end())
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue,
            "SDP SuperOp %s xN edge lookup failed for %d", name().c_str(), xN.e());

    }
    *ret_edge = xEdgeElem->second;

fail:
    return e;
}