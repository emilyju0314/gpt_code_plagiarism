void Lnast_tolg::process_hier_inp_bits_set(LGraph *lg, const Lnast_nid &lnidx_ta) {
  std::string hier_inp_name;
  for (const auto &child : lnast->children(lnidx_ta)) {
    if (child == lnast->get_first_child(lnidx_ta)) {
      const auto &c0_ta = child;
      I(is_input(lnast->get_vname(c0_ta)));
      hier_inp_name = lnast->get_vname(c0_ta).substr(1);
    } else if (lnast->get_vname(child) != "__bits") {
      I(child != lnast->get_last_child(lnidx_ta));
      hier_inp_name = absl::StrCat(hier_inp_name, ".", lnast->get_vname(child));
    } else if (lnast->get_vname(child) == "__bits") { //at the __bits child
      //(1) create flattened input 
      Node_pin flattened_inp;
      if (!lg->is_graph_input(hier_inp_name))
        flattened_inp = lg->add_graph_input(hier_inp_name, Port_invalid, 0);
      else
        flattened_inp = name2dpin[hier_inp_name];

      //(2) create attr_set node for input
      auto aset_node = lg->create_node(Ntype_op::AttrSet);
      auto vn_spin   = aset_node.setup_sink_pin("name");     // variable name
      auto af_spin   = aset_node.setup_sink_pin("field");    // attribute field
      auto av_spin   = aset_node.setup_sink_pin("value");    // attribute value
  
      flattened_inp.connect_sink(vn_spin);
      auto af_dpin = setup_field_dpin(lg, lnast->get_vname(child));   
      af_dpin.connect_sink(af_spin);

      auto const_lnidx = lnast->get_sibling_next(child);
      auto av_dpin = setup_ref_node_dpin(lg, const_lnidx);
      av_dpin.connect(av_spin);
      name2dpin[hier_inp_name] = aset_node.setup_driver_pin("Y");
      break; // no need to iterate to last child
    }
  }
}