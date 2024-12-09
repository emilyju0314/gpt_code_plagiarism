planner_node_type planner_node_name_to_type(const std::string& name) { 

  static std::map<std::string, planner_node_type> name_to_type_map;

  if(name_to_type_map.empty()) {
    for(int i = 0; i < int(planner_node_type::INVALID); ++i) {
      planner_node_type t = static_cast<planner_node_type>(i);
      name_to_type_map[planner_node_type_to_name(t)] = t;
    }
  }

  auto it = name_to_type_map.find(name);

  if(it == name_to_type_map.end()) {
    ASSERT_MSG(false, (std::string("Operator name ") + name + " not found.").c_str());
  }

  return it->second; 
}