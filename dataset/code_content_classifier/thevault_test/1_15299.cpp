NvDlaError engine_ast::Graph::flattenGraph()
{
    NvDlaError e = NvDlaSuccess;
    NodeSequence allNodes = orderedNodes();
    for (NodeSequence::const_iterator ni = allNodes.begin(); ni != allNodes.end(); ++ni)
    {
        if ( (*ni)->engineType() == EngineTypeEnum::MULTI_OPS)
        {
            PROPAGATE_ERROR_FAIL(engine_ast::NodeFactory::nodeCast<MultiOpsNode*>(*ni)->plugNestedGraph());
        }
    }

    // check dirty and re-determine graph order
    checkDirty();
    PROPAGATE_ERROR_FAIL(refreshGraphState());

fail:
    return e;
}