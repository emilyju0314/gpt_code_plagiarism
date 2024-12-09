NvDlaError engine_ast::AddCopyOutDebugBDMA::visitBegin(engine_ast::Graph *g)
{
    m_graph = g;
    m_debugBindId = 0;
    return NvDlaSuccess;
}