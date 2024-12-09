static NvDlaError prependScaleOpForRescaling
(
    engine_ast::Graph *engGraph,
    canonical_ast::Node *canNode,
    engine_ast::Graph::EdgeSequence engSrcEdges,
    engine_ast::Graph::EdgeSequence engSinkEdges,
    engine_ast::Graph::NodeSequence& transformedEngNodes
)
{
    NvDlaError e = NvDlaSuccess;

    engine_ast::SDPScaleOpNode* engSDPScaleNode = NULL;
    surface::SurfacePrecision computePrecision  = engGraph->profile()->computePrecision();
    engine_ast::Edge* engSrcEdge                = NULL;
    engine_ast::Edge* scaleSinkEdge             = NULL;

    Tensor* inTensor = NULL;
    Tensor* outTensor = NULL;

    Dims4 scaleDims;
    engine_ast::SDPMode scaleMode = engine_ast::SDPModeEnum::SDP_MODE_PER_CHANNEL; // Force it to per-channel

    if (engSrcEdges.size() != 1 || engSinkEdges.size() != 1)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported, "Don't support Activation operation with input edges (%d) != 1 or "
                                                   "output edges (%d) != 1", engSrcEdges.size(), engSinkEdges.size());
    }

    if (computePrecision.v() != surface::SurfacePrecisionEnum::NVDLA_PRECISION_INT8)
    {
        /* Rescaling applicable for only int8 */
        goto fail;
    }

    /* Create a new sdp node */
    engSDPScaleNode = engine_ast::NodeFactory::newSDPScaleOpNode(NULL, engGraph);

    /* Create an output tensor for newscale node and uses the same as that next canNode */
    outTensor = canNode->outputEdges().at(0)->originalTensor()->clone();
    outTensor->setTensorType(TensorType::kIO);

    /* Determine the scaling dimension based on scale mode */
    inTensor = canNode->inputEdges().at(0)->originalTensor();
    scaleDims.n = 1;
    scaleDims.c = inTensor->getDimensions().c;
    scaleDims.h = 1;
    scaleDims.w = 1;

    /* Update the params of engScaleNode. */
    engSDPScaleNode->populateWithUnitScaleParams(scaleMode, scaleDims);

    /* create an new edge from output of scale to input of canNode */
    engSrcEdge  = engSrcEdges[0];
    scaleSinkEdge = engGraph->addDataEdge((engine_ast::Edge*)0,
                            (engine_ast::Node*)0,
                            (engine_ast::Node*)0,
                            outTensor);
    engGraph->appendNodeToEdge(engSrcEdge, ast::EdgeSideEnum::SECOND, engSDPScaleNode);
    engGraph->appendNodeToEdge(scaleSinkEdge, ast::EdgeSideEnum::FIRST, engSDPScaleNode);

    PROPAGATE_ERROR_FAIL(engSDPScaleNode->populateEdgePorts());
    transformedEngNodes.push_back(engSDPScaleNode);
fail:
    return e;
}