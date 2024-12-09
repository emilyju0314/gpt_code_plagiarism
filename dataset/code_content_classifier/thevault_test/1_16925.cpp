void GammaHNSW::AddLinksStartingFrom(DistanceComputer& ptdis,
                                   storage_idx_t pt_id,
                                   storage_idx_t nearest,
                                   float d_nearest,
                                   int level,
                                   omp_lock_t *locks)
{
  std::priority_queue<NodeDistCloser> link_targets;

  search_neighbors_to_add(*this, ptdis, link_targets, nearest, d_nearest,
                          level);

  // but we can afford only this many neighbors
  int M = nb_neighbors(level);

  tig_gamma::shrink_neighbor_list(ptdis, link_targets, M);

  while (!link_targets.empty()) {
    int other_id = link_targets.top().id;

    omp_set_lock(&locks[other_id]);
    add_link(*this, ptdis, other_id, pt_id, level);
    omp_unset_lock(&locks[other_id]);

    add_link(*this, ptdis, pt_id, other_id, level);

    link_targets.pop();
  }
}