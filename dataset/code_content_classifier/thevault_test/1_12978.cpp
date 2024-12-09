void Code_gen::do_cond(const mmap_lib::Tree_index& cond_node_index) {
  fmt::print("node:cond\n");
  //const auto& curr_node_data = lnast->get_data(cond_node_index);
  std::string_view ref = lnast->get_name(cond_node_index);
  auto map_it = ref_map.find(ref);
  if(map_it != ref_map.end()) {
    ref = map_it->second;
  }
  absl::StrAppend(&buffer_to_print, lnast_to->ref_name(ref));
  absl::StrAppend(&buffer_to_print, lnast_to->end_cond());
}