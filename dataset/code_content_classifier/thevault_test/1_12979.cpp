void Code_gen::do_dot(const mmap_lib::Tree_index& dot_node_index) {
  fmt::print("node:dot\n");

  auto curr_index = lnast->get_first_child(dot_node_index);
  std::vector<std::string_view> dot_str_vect;
  while(curr_index!=lnast->invalid_index()) {
    assert(!(lnast->get_type(curr_index)).is_invalid());
    auto curlvl = curr_index.level;
    fmt::print("Processing dot child {}:{} at level {} \n",lnast->get_name(curr_index), lnast->get_type(curr_index).debug_name(), curlvl);
    dot_str_vect.push_back(lnast->get_name(curr_index));
    curr_index = lnast->get_sibling_next(curr_index);
  }
  //dot_str_vect now has all the children of the operation "op"

  assert(dot_str_vect.size()>2);
  auto key = dot_str_vect.front();

  auto i = 1u;
  std::string value;
  const auto& dot_node_data = lnast->get_data(dot_node_index);
  while (i<dot_str_vect.size()) {
    auto ref = std::string(dot_str_vect[i]);
    auto map_it = ref_map.find(ref);
    if (map_it != ref_map.end()) {
      ref = map_it->second;
    }
    //absl::StrAppend(&value, ref);
    if (ref=="__valid") {
      value.pop_back();
      absl::StrAppend(&value, "?");
    } else if (ref=="__retry") {
      value.pop_back();
      absl::StrAppend(&value, "!");
    } else {
      absl::StrAppend(&value, ref);
    }
    if (is_number(ref)) {
      absl::StrAppend(&value, process_number(ref));
    }
    absl::StrAppend(&value, lnast_to->debug_name_lang(dot_node_data.type));//appends "." after the value in case of pyrope
    i++;
  }
  value.pop_back();

  if (is_temp_var(key)) {
    //ref_map.insert(std::pair<std::string_view, std::string>(key, lnast_to->ref_name(value)));
    //this value is preserved with "$"/"%"/"#" so that during "convert_parameters()", we have the char to decide i/p or o/p or reg
    auto ref_map_inst_succ = ref_map.insert(std::pair<std::string_view, std::string>(key, value));
    I(ref_map_inst_succ.second, "\n\nThe ref value was already in the ref_map. Thus redundant keypresent. BUG!\nParent_node : dot\n\n");
  } else {
    absl::StrAppend(&buffer_to_print, indent(), key, " saved as ", lnast_to->ref_name(value), "\n");
    // this should never be possible
  }

}