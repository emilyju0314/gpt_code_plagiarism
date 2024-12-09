NvDlaError engine_ast::Graph::mergeUnitScaleOperations()
{
    NvDlaError e = NvDlaSuccess;
    NodeSequence allNodes = orderedNodes();
    NodeSequenceIterator ni = allNodes.begin();
    NodeSequenceIterator startNodeIter = ni;
    bool maxOptimized = false;
    Node* currNode   = NULL;
    Node* prevNode   = NULL;
    Node* removeNode = NULL;

    do
    {
        for (ni = startNodeIter; ni != allNodes.end(); ++ni)
        {
            if ((*ni)->engineType().v() != EngineTypeEnum::SDP)
            {
                continue;
            }

            NodeSequence sinkNodes = downstreamDataNodes((*ni));
            /* Attempt to combine only those sdp nodes which are 1:1 connected and
             * not part of a multi-way junction
             */
            if ( sinkNodes.size() != 1 || upstreamDataNodes(sinkNodes[0]).size() != 1 ||
                 sinkNodes[0]->engineType().v() != EngineTypeEnum::SDP )
            {
                continue;
            }

            currNode   = *ni;
            prevNode   = ni != allNodes.begin() ? *(ni - 1) : *ni;
            SDPNode* currSDP = NodeFactory::nodeCast<SDPNode*>(currNode);
            SDPNode* nextSDP = NodeFactory::nodeCast<SDPNode*>(sinkNodes[0]);
            if ( nextSDP->engineOpType().v() != EngineOpTypeEnum::SDP_SCALE )
            {
                continue;
            }

            if ( !nextSDP->isUnitScale() )
            {
                continue;
            }

            if ( debugMathOptz() )
            {
                gLogInfo << std::endl;
                gLogInfo << "Try Merging: " << currNode->name() << " & " << nextSDP->name() << std::endl;
            }

            removeNode = currSDP->mergeUnitScaleOp(nextSDP);

            if ( debugMathOptz() )
            {
                if (removeNode)
                    gLogInfo << "Merging: Sucess" << std::endl;
                else
                    gLogInfo << "Merging: Not Feasible" << std::endl;
            }

            if ( removeNode )
            {
                IODirection iod = IODirectionEnum::INPUT;

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

fail:
    return e;
}