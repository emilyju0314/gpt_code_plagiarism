void Code_gen::generate(){
  const auto& root_index = lnast->get_root();
  const auto& node_data = lnast->get_data(root_index);
  fmt::print("\n\nprocessing LNAST tree\n\n");
  if (node_data.type.is_top()) {
    fmt::print("\nprocessing LNAST tree root text: {} ", node_data.token.get_text());
    fmt::print("processing root->child");
    indendation = lnast_to->indent_final_system();
  //for CPP:  absl::StrAppend(&buffer_to_print, lnast_to->starter(lnast->get_top_module_name()));
    do_stmts(lnast->get_child(root_index));
  } else if (node_data.type.is_invalid()) {
    fmt::print("INVALID NODE!");
  } else {
    fmt::print("UNKNOWN NODE TYPE!");
  }

  auto lang_type = lnast_to->get_lang_type();//which lang is it? prp/cpp/verilog
  std::string modname = std::string(lnast->get_top_module_name());//this was of type const originally, needed it to be string.

  //for debugging purposes only:
  lnast_to->call_get_maps();
  for (auto const& [key, val] : ref_map) {
    fmt::print("For map key: {}, val is: {}\n", key, val);
  }

  fmt::print("lnast_to_{}_parser path:{} \n", lang_type, path);

  //header file:
  auto basename_s = absl::StrCat(modname, ".", lnast_to->supporting_ftype());
  fmt::print("{}\n", lnast_to->supporting_fstart(basename_s));
  fmt::print("{}\n", lnast_to->supp_buffer_to_print(modname));
  fmt::print("{}\n", lnast_to->supporting_fend(basename_s));

  //main file:
  auto basename = absl::StrCat(modname, ".", lang_type);
  //header inclusion:(#includes):
  fmt::print("{}\n", lnast_to->main_fstart(basename, basename_s));
  fmt::print("{}\n", lnast_to->final_print(modname, buffer_to_print));
  //:main code segment
  //fmt::print("{}\n", buffer_to_print);
  fmt::print("<<EOF\n");

  //for odir part:
  auto fname   = lnast->get_top_module_name();
  lnast_to->result_in_odir(fname, odir, buffer_to_print);

}