void kitfox_proxy_t::add_manifold_node(CompId_t CompId, KitFoxType t)
{
    /* Check if there already exists the same node ID. */
    for(auto comp: manifold_node) {
        if(comp.first == CompId) { return; }
    }

    manifold_node.push_back(make_pair(CompId, t));
}