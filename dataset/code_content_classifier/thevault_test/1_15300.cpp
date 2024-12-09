NvDlaError engine_ast::Graph::resolveComputeDependencies(const NodeSequence& allNodes)
{
    NvDlaError e = NvDlaSuccess;
    for (NodeSequence::const_iterator ni = allNodes.begin(); ni != allNodes.end(); ++ni)
    {
        PROPAGATE_ERROR_FAIL((*ni)->resolveComputeDependencies(allNodes));
    }

fail:
    return e;
}