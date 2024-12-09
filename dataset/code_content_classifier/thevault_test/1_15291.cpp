vector<engine_ast::Edge *> engine_ast::Graph::siblingDataEdges(engine_ast::Edge* edge)
{
    EdgeSequence es;
    NodeSequence inputNodes = upstreamNodes(edge);

    for (NodeSequenceIterator ni = inputNodes.begin(); ni != inputNodes.end(); ++ni)
    {
        EdgeSequence outputEdges = downstreamDataEdges(*ni);
        for (EdgeSequenceIterator ei = outputEdges.begin(); ei != outputEdges.end(); ++ei)
        {
            if ((*ei) != edge)
            {
                es.push_back(*ei);
            }
        }
    }

    return es;
}