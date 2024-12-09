NvDlaError engine_ast::Graph::substituteNodeInAST(Node* origNode, NodeSequence subNodes)
{
    NvDlaError e = NvDlaSuccess;

    Node* headSubNode = subNodes.front();
    Node* tailSubNode = subNodes.back();
    NodeSequence origNodeSrcNodes  = upstreamNodes(origNode);
    EdgeSequence origNodeSrcEdges  = upstreamEdges(origNode);
    EdgeSequence origNodeSinkEdges = downstreamEdges(origNode);

    /* Delegate all input edge(s) to the substitute node */
    for (EdgeSequenceIterator uei = origNodeSrcEdges.begin(); uei != origNodeSrcEdges.end(); ++uei)
    {
        if ( (*uei)->isAuxEdge() )
        {
            continue;
        }
        replaceEdgeNodes(*uei, ast::EdgeSideEnum::SECOND, origNode, headSubNode);
    }

    /* Delegate all output edge(s) to the substitute node */
    for (EdgeSequenceIterator dei = origNodeSinkEdges.begin(); dei != origNodeSinkEdges.end(); ++dei)
    {
        replaceEdgeNodes(*dei, ast::EdgeSideEnum::FIRST, origNode, tailSubNode);
    }

    /* Repopulate the edge ports of the substitute node after this edge upheaval */
    for (NodeSequenceIterator sni = subNodes.begin(); sni != subNodes.end(); ++sni)
    {
        PROPAGATE_ERROR_FAIL( (*sni)->repopulateEdgePorts() );
    }

fail:
    return e;
}