bool Dependency::hasVertex(const std::string& name)
{
    boost::property_map<DependencyGraph, property_tag_t>::type
        index = boost::get(property_tag_t(), m_graph);

    boost::graph_traits<DependencyGraph>::vertex_iterator
        i = boost::vertices(m_graph).first;
    for (; i != vertices(m_graph).second; i++)
    {
        if (index[*i] == name)
        {
            return true;
        }
    }

    return false;
}