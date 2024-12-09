NvDlaError engine_ast::SplitNode::populateEdgePorts()
{
    NvDlaError e = NvDlaSuccess;

    typedef engine_ast::Graph::EdgeSequence EngineEdges;
    typedef engine_ast::Graph::EdgeSequenceIterator EngineEdgeIterator;

    typedef canonical_ast::Graph::EdgeSequence CanonicalEdges;
    typedef canonical_ast::Graph::EdgeSequenceIterator CanonicalEdgeIterator;

    EngineEdges engInEdges = graph()->upstreamDataEdges(this);
    EngineEdges engOutEdges = graph()->downstreamDataEdges(this);


    if (engInEdges.size() > 1)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s has > 1 input edges", name().c_str());
    }
    else
    {
        markInputEdge(engInEdges[0]);
    }

    // if canonical equivalent exists, use order of output edge insertions in canonical land to establish strict order
    if (canonicalNode())
    {
        CanonicalEdges canOutEdges = canonicalNode()->outputEdges();
        for (CanonicalEdgeIterator cei = canOutEdges.begin(); cei != canOutEdges.end(); ++cei)
        {
            IsSameCanonicalEdge match_can_edge(*cei);
            EngineEdgeIterator eei = std::find_if(engOutEdges.begin(), engOutEdges.end(), match_can_edge);
            if (eei == engOutEdges.end())
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s is not an output edge of %s", (*eei)->id().c_str(), name().c_str());
            }
            markOutputEdge(*eei);
        }
    }
    // else simply mark output edges in order of appearance
    else
    {
        for (EngineEdgeIterator eei = engOutEdges.begin(); eei != engOutEdges.end(); ++eei)
        {
            markOutputEdge(*eei);
        }
    }

    PROPAGATE_ERROR_FAIL(verifyEdgePorts());
fail:
    return e;
}