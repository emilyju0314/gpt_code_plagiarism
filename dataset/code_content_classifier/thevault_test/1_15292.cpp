NvDlaError engine_ast::Graph::removeNodeFromAST(Node* killNode, IODirection iod)
{
    NvDlaError e = NvDlaSuccess;

    NodeSequence ioSideNodes;
    EdgeSequence ioSideEdges;
    EdgeSequence oppSideEdges;
    Edge* killNodeAuxEdge = NULL;

    if (iod.v() == IODirectionEnum::UNKNOWN)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Can't remove node unless the "
                "I/O direction of edges to trim is specified: %s", iod.c_str());
    }

    ioSideNodes  = iod.v() == IODirectionEnum::INPUT ? upstreamNodes(killNode) : downstreamNodes(killNode);
    ioSideEdges  = iod.v() == IODirectionEnum::INPUT ? upstreamEdges(killNode) : downstreamEdges(killNode);
    oppSideEdges = iod.v() == IODirectionEnum::INPUT ? downstreamEdges(killNode) : upstreamEdges(killNode);

    killNode->nodeAuxEdge(&killNodeAuxEdge);

    /* Transfer that set of edge(s) of the node_to_be_removed which are going to stay in the graph -
     * to the node(s) on the opposite side
     */
    for (EdgeSequenceIterator oppsei = oppSideEdges.begin(); oppsei != oppSideEdges.end(); ++oppsei)
    {
        if ((*oppsei)->isAuxEdge())
        {
            continue;
        }

        for (NodeSequenceIterator iosni = ioSideNodes.begin(); iosni != ioSideNodes.end(); ++iosni)
        {
            if (iod.v() == IODirectionEnum::INPUT)
            {
                replaceEdgeNodes(*oppsei, ast::EdgeSideEnum::FIRST, killNode, *iosni);
            }
            else
            {
                replaceEdgeNodes(*oppsei, ast::EdgeSideEnum::SECOND, killNode, *iosni);
            }
        }
    }

    /* Detach and delete the specified I/O side edge(s) from the node_to_be_removed and the
     * node(s) on the other side of those edge(s)
     */
    for (EdgeSequenceIterator iosei = ioSideEdges.begin(); iosei != ioSideEdges.end(); ++iosei)
    {
        if ((*iosei)->isAuxEdge())
        {
            continue;
        }

        for (NodeSequenceIterator iosni = ioSideNodes.begin(); iosni != ioSideNodes.end(); ++iosni)
        {
            if (iod.v() == IODirectionEnum::INPUT)
            {
                removeEdgeFromNode(*iosei, ast::EdgeSideEnum::FIRST, *iosni);
                removeNodeFromEdge(*iosei, ast::EdgeSideEnum::FIRST, *iosni);
            }
            else
            {
                removeEdgeFromNode(*iosei, ast::EdgeSideEnum::SECOND, *iosni);
                removeNodeFromEdge(*iosei, ast::EdgeSideEnum::SECOND, *iosni);
            }
        }

        if (iod.v() == IODirectionEnum::INPUT)
        {
            removeEdgeFromNode(*iosei, ast::EdgeSideEnum::SECOND, killNode);
            removeNodeFromEdge(*iosei, ast::EdgeSideEnum::SECOND, killNode);
        }
        else
        {
            removeEdgeFromNode(*iosei, ast::EdgeSideEnum::FIRST, killNode);
            removeNodeFromEdge(*iosei, ast::EdgeSideEnum::FIRST, killNode);
        }

        resourceMgr()->unregTensorSurfaceDesc((*iosei)->tensorSurfaceDesc());
        resourceMgr()->unregTensorBufferDesc((*iosei)->tensorBufferDesc());
        removeEdge(*iosei);
    }

    /* Repopulate the edge ports of the affected node(s) after this edge upheaval */
    for (NodeSequenceIterator iosni = ioSideNodes.begin(); iosni != ioSideNodes.end(); ++iosni)
    {
        PROPAGATE_ERROR_FAIL((*iosni)->repopulateEdgePorts());
    }

    /* Detach and delete the aux edge (if any) of the node_to_be_removed */
    if (killNodeAuxEdge)
    {
        removeEdgeFromNode(killNodeAuxEdge, ast::EdgeSideEnum::SECOND, killNode);
        removeNodeFromEdge(killNodeAuxEdge, ast::EdgeSideEnum::SECOND, killNode);
        resourceMgr()->unregTensorSurfaceDesc(killNodeAuxEdge->tensorSurfaceDesc());
        resourceMgr()->unregTensorBufferDesc(killNodeAuxEdge->tensorBufferDesc());
        removeEdge(killNodeAuxEdge);
        delete killNodeAuxEdge;
    }

    /* Finally remove the node */
    removeNode(killNode);
    delete killNode;
    killNode = NULL;

fail:
    return e;
}