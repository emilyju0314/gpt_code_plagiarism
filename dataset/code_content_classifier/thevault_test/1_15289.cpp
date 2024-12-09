NvDlaError engine_ast::SDPScaleOpNode::configureSDPSuperOpSubEngine(SDPSuperOpNode* sdpSuperOp, SDPSubEngineType xN)
{
    NvDlaError e = NvDlaSuccess;

    if (xN == SDP_ENGINE_X1)
    {
        sdpSuperOp->params().setX1Params(params().x1Params());
        sdpSuperOp->params().setConvMode(params().convMode());
        sdpSuperOp->params().setWinogradParams(params().winogradParams());
    }
    else
    {
        sdpSuperOp->params().setX2Params(params().x1Params());
    }

    sdpSuperOp->params().setAuxDataType(xN, TensorType::kSCALE);

    sdpSuperOp->params().setMultiplierDims(xN, params().scaleDims());
    sdpSuperOp->params().setDLADataDims(xN, params().scaleDims());

    sdpSuperOp->params().setRawMultiplierData(xN, params().rawScaleData());
    sdpSuperOp->params().setDLAData(xN, params().DLAScaleData());

    sdpSuperOp->params().setAuxSurfaceFormats(xN, suggestAuxSurfaceFormats());

    if ( graph()->debugFuseSubEngineOps() )
    {
        gLogInfo << "configureSDPSuperOpSubEngine: " << this->name() << " in ";
        gLogInfo << sdpSuperOp->name() << " x" << (NvU16)xN.e()+1 << endl;
    }

    return e;
}