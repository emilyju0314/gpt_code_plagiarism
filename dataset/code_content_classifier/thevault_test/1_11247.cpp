std::string planner_node_repr(const std::shared_ptr<planner_node>& node) {

  std::map<pnode_ptr, std::string> names;
  pnode_tagger get_tag = [&](pnode_ptr p) -> std::string {
    auto it = names.find(p);
    if(it == names.end()) {
      auto s = to_name(names.size());
      names[p] = s;
      return s;
    } else {
      return it->second;
    }
  };

  return get_tag(node) + ": " + extract_field<visitor_repr, std::string>(node->operator_type, node, get_tag);
}