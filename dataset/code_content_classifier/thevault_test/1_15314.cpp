NvDlaError engine_ast::SDPElementWiseOpNode::configureSDPSuperOpSubEngine(SDPSuperOpNode* sdpSuperOp, SDPSubEngineType xN)
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

    sdpSuperOp->params().setOutCVT(params().outCVT());
    sdpSuperOp->params().setAuxDataType(xN, TensorType::kIO);

    if ( graph()->debugFuseSubEngineOps() )
    {
        gLogInfo << "configureSDPSuperOpSubEngine: " << this->name() << " in ";
        gLogInfo << sdpSuperOp->name() << " x" << (NvU16)xN.e()+1 << endl;
    }

    return e;
}