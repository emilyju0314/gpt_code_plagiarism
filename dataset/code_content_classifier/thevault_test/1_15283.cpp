const std::vector<surface::SurfaceCategory> engine_ast::Node::supportedInSurfCategories() const
{
    std::vector<surface::SurfaceCategory> supported_scs_v;
    std::set<surface::SurfaceCategory, SequenceEnumCompare<surface::SurfaceCategory>> supported_scs;
    for (size_t ss = 0; ss < supportedInSurfFormats().size(); ++ss)
    {
        supported_scs.insert(supportedInSurfFormats()[ss].f().category());
    }
    supported_scs_v.resize(supported_scs.size());
    std::copy(supported_scs.begin(), supported_scs.end(), supported_scs_v.begin());
    return supported_scs_v;
}