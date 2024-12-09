static length_info propagate_length(
    const pnode_ptr& n, std::map<pnode_ptr, length_info>& visited) {
  auto it = visited.find(n);
  if(it != visited.end()) return it->second;

  auto inferred_length = infer_planner_node_length(n);
  if (inferred_length >= 0) {
    length_info li{inferred_length, nullptr};
    visited[n] = li;
    return li;
  }

  if(is_linear_transform(n)) {
    ASSERT_FALSE(n->inputs.empty());
    auto li = propagate_length(n->inputs.front(), visited);
    visited[n] = li;
    return li;
  } else {
    return length_info{-1, n.get()};
  }
}