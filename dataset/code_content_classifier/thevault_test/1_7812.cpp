void
Rtree::join_aux_point_point(JoinElement & j_el, join_pair_result & item,
                            int exploration_model)
{
    // handle the final point to point
    // regardless of exploration model, its only 1 to 1
    assert(j_el.first.is_data && j_el.second.is_data); // they are points
    assert(NULL == j_el.first.the_node && NULL == j_el.second.the_node); // ensure correctness
    assert(j_el.first .target_node_explored);
    assert(j_el.second.target_node_explored);
    item.distance = j_el.dist;
    item.first.the_id = j_el.first.the_id;
    item.first.rect = j_el.first.the_mbr;
    item.second.the_id = j_el.second.the_id;
    item.second.rect = j_el.second.the_mbr;
}