NvDlaError engine_ast::Graph::fuseSDPSubEngineOps()
{
    NvDlaError e = NvDlaSuccess;
    NodeSequence allNodes = orderedNodes();
    NodeSequenceIterator ni = allNodes.begin();
    NodeSequenceIterator startNodeIter = ni;
    bool maxOptimized = false;
    Node* currNode   = NULL;
    Node* prevNode   = NULL;
    Node* removeNode = NULL;

    if (!profile()->canSDPFuseSubEngineOps())
    {
        // nothing to do
        goto fail;
    }

    if (debugFuseSubEngineOps())
    {
        printGraph(this, true, "pree fuseSDPSubEngineOps");
    }

    do
    {
        for (ni = startNodeIter; ni != allNodes.end(); ++ni)
        {
            /* Only SDP ops can be fused. */
            if ((*ni)->engineType().v() != EngineTypeEnum::SDP)
            {
                continue;
            }

            NodeSequence sinkNodes = downstreamDataNodes((*ni));
            /* Attempt to combine only those sdp nodes which are 1:1 connected and
             * not part of a multi-way junction
             */
            if ( sinkNodes.size() != 1 || upstreamDataNodes(sinkNodes[0]).size() > 2 ||
                 sinkNodes[0]->engineType().v() != EngineTypeEnum::SDP )
            {
                continue;
            }

            currNode   = *ni;
            prevNode   = ni != allNodes.begin() ? *(ni - 1) : *ni;
            SDPNode* currSDP = NodeFactory::nodeCast<SDPNode*>(currNode);
            SDPNode* nextSDP = NodeFactory::nodeCast<SDPNode*>(sinkNodes[0]);

            if ( debugFuseSubEngineOps() )
            {
                gLogInfo << std::endl;
                gLogInfo << "Try Fusing: " << currNode->name() << " & " << nextSDP->name() << std::endl;
            }

            removeNode = currSDP->fuseSDPSubEngineOp(nextSDP);

            if ( debugFuseSubEngineOps() )
            {
                if (removeNode)
                    gLogInfo << "Fusing: Sucess" << std::endl;
                else
                    gLogInfo << "Fusing: Not Feasible" << std::endl;
            }

            if (removeNode)
            {
                IODirection iod;
                NodeSequence gNodes = orderedNodes();

                /* Before removing, delegate operation mode to the next op iff it exists;
                 * don't bother if it is already removed from graph
                 */
                if ((removeNode == currNode) && (std::find(gNodes.begin(), gNodes.end(), nextSDP) != gNodes.end()))
                {
                    SDPNode* removeSDP = NULL;
                    ASSERT(removeNode->engineType().v() == EngineTypeEnum::SDP);
                    removeSDP = NodeFactory::nodeCast<SDPNode*>(removeNode);
                    nextSDP->params().setConvMode(removeSDP->params().convMode());
                    nextSDP->params().setWinogradParams(removeSDP->params().winogradParams());
                    nextSDP->params().setNumGroups(removeSDP->params().numGroups());
                }
                iod = (removeNode == currNode) ? IODirectionEnum::OUTPUT : IODirectionEnum::INPUT;
                PROPAGATE_ERROR_FAIL( removeNodeFromAST(removeNode, iod) );
                break;
            }
        }

        // if the last pass through all nodes didn't change the AST anymore,
        // that means all optimizations are applied; no more scope left
        if ( ni == allNodes.end() )
        {
            maxOptimized = true;
        }
        else
        {
            // rinse and repeat on newly ordered nodes;
            // starting from the node prior to the recently operated one
            allNodes = orderedNodes();
            startNodeIter = std::find(allNodes.begin(), allNodes.end(), prevNode);
            if (startNodeIter == allNodes.end())
            {
                startNodeIter = allNodes.begin();   // just in case
            }
            PROPAGATE_ERROR_FAIL(refreshGraphState());
        }
    } while(!maxOptimized);

    // check dirty and re-determine graph order
    checkDirty();
    PROPAGATE_ERROR_FAIL(refreshGraphState());

    if (debugFuseSubEngineOps())
    {
        printGraph(this, true, "post fuseSDPSubEngineOps");
    }

fail:
    return e;
}