const StringList Dependency::getDependency(const std::string& modid)
{
    Locker lock(this);
    StringList list;
    typedef boost::graph_traits<DependencyGraph> GraphTraits;
    boost::property_map<DependencyGraph, property_tag_t>::type
        index = boost::get(property_tag_t(), m_graph);
    GraphTraits::adjacency_iterator ai, ai_end;

    for (boost::graph_traits<DependencyGraph>::vertex_iterator i =
             boost::vertices(m_graph).first;
         i != vertices(m_graph).second; i++)
    {
        if (index[*i] == modid)
        {
            for (boost::tie(ai, ai_end) = boost::adjacent_vertices(*i, m_graph);
                 ai != ai_end; ++ai)
            {
                list.push_back(index[*ai]);
            }
            break;
        }
    }
    return list;
}