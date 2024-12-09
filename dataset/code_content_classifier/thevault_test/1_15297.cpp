NvDlaError engine_ast::Graph::updateScalingFactors()
{
    NvDlaError e = NvDlaSuccess;
    NodeSequence allNodes = orderedNodes();

    if (profile()->computePrecision().v() != surface::SurfacePrecisionEnum::NVDLA_PRECISION_INT8)
    {
        // nop
        goto fail;
    }

    if ( profile()->tensorScalingMode().v() != nvdla::TensorScalingMode::PER_TENSOR )
    {
        // don't support any other scaling mode than PER_TENSOR
        ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported, "Don't support tensor scaling mode: %s\n",
                                profile()->tensorScalingMode().c_str());
    }

    for (NodeSequence::const_iterator ni = allNodes.begin(); ni != allNodes.end(); ++ni)
    {
        engine_ast::Node* currNode = *ni;

        EngineOpType eng_op_type = currNode->engineOpType();

        EdgeSequence inputEdges;
        EdgeSequence siblingEdges0;
        EdgeSequence siblingEdges1;

        engine_ast::Edge* inputEdge0 = NULL;
        engine_ast::Edge* inputEdge1 = NULL;
        engine_ast::Edge* updateEdge = NULL;

        std::vector<NvF32> inputTensorScales0;
        std::vector<NvF32> inputTensorScales1;
        std::vector<NvF32> updateTensorScales;

        if (eng_op_type.v() != EngineOpTypeEnum::SDP_ELEMENTWISE)
        {
            continue;
        }

        inputEdges = upstreamDataEdges(currNode);

        /* element wise op should have exactly two input edges. */
        if (inputEdges.size() != 2)
        {
            ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Elt wise op has input edges (%d) != 2 ", inputEdges.size());
        }

        inputEdge0 = inputEdges.at(0);
        inputTensorScales0 = inputEdge0->originalTensor()->getChannelScales();

        inputEdge1 = inputEdges.at(1);
        inputTensorScales1 = inputEdge1->originalTensor()->getChannelScales();

        ASSERT (inputTensorScales0.size() == inputTensorScales1.size())
        if (inputTensorScales0.at(0) == inputTensorScales1.at(0))
        {
            // Incoming scale values are same, no need for update.
            continue;
        }

        siblingEdges0 = siblingDataEdges(inputEdge0);
        siblingEdges1 = siblingDataEdges(inputEdge1);

        /**
         * Elementwise fusion has 3 possible cases
         * 1. Both input nodes to elementwise layer has single output edges
         * 2. One input node has multiple output edges while another has single output edge
         * 3. Both input nodes to elementwise layer has multiple output edges
         *
         * #1, any of the input nodes can be rescaled using scaling factor of another
         *     node. it requires selecting correct scaling factor to use.
         * #2, general policy is to rescale node with single output edge as rescaling
         *     node with multiple edges will cause incorrect input to another node
         * #3, in such case, we need to select scaling factor from two input nodes
         *     and use new SDP scaling node to rescaling
         *
         * Current implementation support #1 and #2, but does not support scaling factor
         * selection for #1.
         */

        if (siblingEdges0.size() == 0 && siblingEdges1.size() == 0)
        {
            /* case 1 */
            updateEdge = inputEdge0;
            updateTensorScales = inputTensorScales1;
        }
        else if (siblingEdges0.size() == 0)
        {
            /** case 2:
             *   when no src node corresponding to first input edge exists (or)
             *      when src node corresponding to first input edge exists, having only
             *      one output edge = first input edge
             *   In other words, no siblings to first input edge
             *   Handled in similar way as that of case 1
             **/
            updateEdge = inputEdge0;
            updateTensorScales = inputTensorScales1;
        }
        else if (siblingEdges1.size() == 0)
        {
            /** case 2:
             *   when no src node corresponding to second input edge exists (or)
             *      when src node corresponding to second input edge exists, having only
             *      one output edge = second input edge
             *   In other words, no siblings to second input edge
             *   Handled in similar way as that of case 1
             **/
            updateEdge = inputEdge1;
            updateTensorScales = inputTensorScales0;
        }
        else
        {
            /* TODO: to handle case 3: when both input nodes have multiple outputs */
            ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported,
                                "Both input nodes having multiple output edges is not supported yet!");
        }
        updateEdge->originalTensor()->setChannelScales(updateTensorScales);

    }

    // check dirty and re-determine graph order
    checkDirty();
    PROPAGATE_ERROR_FAIL(refreshGraphState());

fail:
    return e;
}