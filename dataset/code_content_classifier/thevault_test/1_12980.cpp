std::string Code_gen::resolve_tuple_assign(const mmap_lib::Tree_index& tuple_assign_index) {

  auto curr_index = lnast->get_first_child(tuple_assign_index);
  std::vector<std::string_view> op_str_vect;

  while(curr_index!=lnast->invalid_index()) {
    assert(!(lnast->get_type(curr_index)).is_invalid());
    //const auto& curr_node_data = lnast->get_data(curr_index);
    op_str_vect.push_back(lnast->get_name(curr_index));
    curr_index = lnast->get_sibling_next(curr_index);
  }
  //op_str_vect now has all the children of the operation "op"

  auto key = op_str_vect.front();
  bool is_const = false;
  std::string val = "";
  const auto& op_node_data = lnast->get_data(tuple_assign_index); //the operator (assign or as)

  if (key == "null") {
    is_const = true;
    val = op_str_vect.back();
    //val = op_str_vect[1];
  } else {
    bool op_is_unary = false;
    if(is_temp_var(key) && op_str_vect.size()==2) {
      op_is_unary = true;
    }

    for (unsigned i = 1; i < op_str_vect.size(); i++) {
      auto ref = std::string(op_str_vect[i]);
      if (ref=="null") {
        val="";
        break;
      }
      auto             map_it = ref_map.find(ref);
      if (map_it != ref_map.end()) {
        if (std::count(map_it->second.begin(), map_it->second.end(), ' ')) {
          ref = absl::StrCat("(", map_it->second, ")");
        } else {
          ref = map_it->second;
        }
       // fmt::print("map_it find: {} | {}\n", map_it->first, ref);
      } else if (is_number(ref)) {
        ref = process_number(ref);
      }
      // check if a number
      if(op_is_unary) {absl::StrAppend(&val,lnast_to->debug_name_lang(op_node_data.type));}
      absl::StrAppend(&val, lnast_to->ref_name(ref));
      if ((i+1) != op_str_vect.size() && !op_is_unary) {
        absl::StrAppend(&val, " ", lnast_to->debug_name_lang(op_node_data.type), " ");
      }
    }
  }

  if(is_temp_var(key)) {
    ref_map.insert(std::pair<std::string_view, std::string>(key, val));
    return ("\n\nERROR:\n\t----------------UNEXPECTED TUPLE VALUE!--------------------\n\n");
  } else if (is_const) {
    std::string ret_tup_str = absl::StrCat (indent(), val, lnast_to->tuple_stmt_sep());
    return ret_tup_str;
  } else if (key=="__range_begin") {
    return  absl::StrCat(val, ".");
  } else if (key == "__range_end") {
    return absl::StrCat(".", val);
  } else {
    std::string ret_tup_str = absl::StrCat (indent(), key, " ", lnast_to->debug_name_lang(op_node_data.type), " ", val, lnast_to->tuple_stmt_sep());
    return (ret_tup_str);
  }
}