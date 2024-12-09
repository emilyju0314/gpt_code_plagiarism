NvDlaError engine_ast::Graph::substituteEdgeInAST(Edge* origEdge, Edge* subEdge)
{
    NvDlaError e = NvDlaSuccess;

    NodeSequence origEdgeSrcNodes  = upstreamNodes(origEdge);
    NodeSequence origEdgeSinkNodes = downstreamNodes(origEdge);

    /* Delegate all input side nodes to the substitute edge */
    for (NodeSequenceIterator uni = origEdgeSrcNodes.begin(); uni != origEdgeSrcNodes.end(); ++uni)
    {
        replaceNodeEdges(*uni, ast::EdgeSideEnum::FIRST, origEdge, subEdge);
    }

    /* Delegate all output side nodes to the substitute edge */
    for (NodeSequenceIterator dni = origEdgeSinkNodes.begin(); dni != origEdgeSinkNodes.end(); ++dni)
    {
        replaceNodeEdges(*dni, ast::EdgeSideEnum::SECOND, origEdge, subEdge);
    }

    /* Repopulate the edge ports of the all the nodes after this edge upheaval */
    for (NodeSequenceIterator uni = origEdgeSrcNodes.begin(); uni != origEdgeSrcNodes.end(); ++uni)
    {
        PROPAGATE_ERROR_FAIL((*uni)->repopulateEdgePorts());
    }
    for (NodeSequenceIterator dni = origEdgeSinkNodes.begin(); dni != origEdgeSinkNodes.end(); ++dni)
    {
        PROPAGATE_ERROR_FAIL((*dni)->repopulateEdgePorts());
    }

fail:
    return e;
}