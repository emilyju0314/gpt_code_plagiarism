size_t infer_planner_node_num_dependency_nodes(std::shared_ptr<planner_node> pnode) {
  std::lock_guard<recursive_mutex> GLOBAL_LOCK(global_query_lock);

  std::set<pnode_ptr> seen_node_memo;
  _fill_dependency_set(pnode, seen_node_memo);
  return seen_node_memo.size();
}