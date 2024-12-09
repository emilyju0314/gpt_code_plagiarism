engine_ast::Graph::Graph(const engine_ast::Graph &other_g) :
    GraphBase(other_g),
    m_next_node_id(other_g.m_next_node_id),
    m_next_edge_id(other_g.m_next_edge_id),
    m_graph_input_edges(vector<engine_ast::Edge*>()),
    m_graph_output_edges(vector<engine_ast::Edge*>()),
    m_resource_mgr(other_g.m_resource_mgr),
    m_profile(other_g.m_profile),
    m_targetconfig(other_g.m_targetconfig),
    m_memoryResolver(other_g.m_memoryResolver),
    m_lutManager(other_g.m_lutManager)
{
    NvDlaError e = NvDlaSuccess; // for throw macro
    THROW_ERROR(NvDlaError_InvalidState);
}