Dims4 engine_ast::RubikNode::suggestSurfaceDims(surface::TensorSurfaceDesc* tsd)
{
    NvDlaError e = NvDlaSuccess;
    bool isSrcTSD = false;
    bool isDstTSD = false;
    Dims4 suggestedDims(-1,-1,-1,-1);

    PROPAGATE_ERROR_FAIL( verifyEdgePorts() );

    isSrcTSD = inputEdges()[0]->tensorSurfaceDesc() == tsd;
    isDstTSD = outputEdges()[0]->tensorSurfaceDesc() == tsd;

    if (!isSrcTSD && !isDstTSD)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "TSD %s doesn't belong to %s", tsd->id().c_str(), name().c_str());
    }

    if (isSrcTSD)
    {
        Dims4 inSurfDims(-1,-1,-1,-1);
        Edge* inEdge = inputEdges()[0];
        Node* srcNode = graph()->upstreamNodes(inEdge).size() ? graph()->upstreamNodes(inEdge)[0] : NULL;
        if (srcNode)
        {
            inSurfDims = srcNode->suggestSurfaceDims(inEdge->tensorSurfaceDesc());
        }
        suggestedDims.n = std::max<NvS32>(params().contractOpParams().inDims.n, inSurfDims.n);
        suggestedDims.c = std::max<NvS32>(params().contractOpParams().inDims.c, inSurfDims.c);
        suggestedDims.h = std::max<NvS32>(params().contractOpParams().inDims.h, inSurfDims.h);
        suggestedDims.w = std::max<NvS32>(params().contractOpParams().inDims.w, inSurfDims.w);

        // use this opportunity to update the contract op params if they seem outdated
        if (suggestedDims != params().contractOpParams().inDims)
        {
            RubikEngineParams::ContractOpParams updatedContractOps = params().contractOpParams();
            updatedContractOps.inDims = suggestedDims;
            params().setContractOpParams(updatedContractOps);
        }
    }
    else
    {
        suggestedDims.n = std::max<NvS32>(params().contractOpParams().outDims.n, tsd->dimensions().n);
        suggestedDims.c = std::max<NvS32>(params().contractOpParams().outDims.c, tsd->dimensions().c);
        suggestedDims.h = std::max<NvS32>(params().contractOpParams().outDims.h, tsd->dimensions().h);
        suggestedDims.w = std::max<NvS32>(params().contractOpParams().outDims.w, tsd->dimensions().w);

        // use this opportunity to update the contract op params if they seem outdated
        if (suggestedDims != params().contractOpParams().outDims)
        {
            RubikEngineParams::ContractOpParams updatedContractOps = params().contractOpParams();
            updatedContractOps.outDims = suggestedDims;
            params().setContractOpParams(updatedContractOps);
        }
    }

fail:
    return suggestedDims;
}