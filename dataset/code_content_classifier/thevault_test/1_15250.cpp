NvDlaError engine_ast::ConcatenationNode::populateEdgePorts()
{
    NvDlaError e = NvDlaSuccess;

    typedef engine_ast::Graph::EdgeSequence EngineEdges;
    typedef engine_ast::Graph::EdgeSequenceIterator EngineEdgeIterator;

    typedef canonical_ast::Graph::EdgeSequence CanonicalEdges;
    typedef canonical_ast::Graph::EdgeSequenceIterator CanonicalEdgeIterator;

    EngineEdges engInEdges = graph()->upstreamDataEdges(this);
    EngineEdges engOutEdges = graph()->downstreamDataEdges(this);

    // if canonical equivalent exists, use order of i/o edge insertions in canonical land to establish strict order
    if (canonicalNode())
    {
        CanonicalEdges canInEdges = canonicalNode()->inputEdges();
        for (CanonicalEdgeIterator cei = canInEdges.begin(); cei != canInEdges.end(); ++cei)
        {
            IsSameCanonicalEdge match_can_edge(*cei);
            EngineEdgeIterator eei = std::find_if(engInEdges.begin(), engInEdges.end(), match_can_edge);
            if (eei == engInEdges.end())
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s is not an input edge to %s", (*eei)->id().c_str(), name().c_str());
            }
            markInputEdge(*eei);
        }
    }
    // else simply mark input edges in order of appearance
    else
    {
        for (EngineEdgeIterator eei = engInEdges.begin(); eei != engInEdges.end(); ++eei)
        {
            markInputEdge(*eei);
        }
    }

    if (engOutEdges.size() > 1)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s has > 1 output edges", name().c_str());
    }
    else
    {
        markOutputEdge(engOutEdges[0]);
    }

    PROPAGATE_ERROR_FAIL(verifyEdgePorts());

fail:
    return e;
}