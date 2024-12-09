const StringList Dependency::getSortedList()
{
    Locker lock(this);
    StringList list;

    typedef std::list<Vertex> container;
    container c;

    // do sort
    boost::topological_sort(m_graph, std::back_inserter(c));
    // retrive all vertexes
    boost::property_map<DependencyGraph, property_tag_t>::type
        index = boost::get(property_tag_t(), m_graph);
    for (container::reverse_iterator i = c.rbegin(); i != c.rend(); ++i)
        list.push_back(index[*i]);

    return list;
}