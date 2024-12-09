Node Lnast_tolg::setup_node_opr_and_lhs(LGraph *lg, const Lnast_nid &lnidx_opr) {
  auto lhs       = lnast->get_first_child(lnidx_opr);
  auto lhs_name  = lnast->get_sname(lhs);
  auto lhs_vname = lnast->get_vname(lhs);

  auto lg_ntype_op = decode_lnast_op(lnidx_opr);
  auto lg_opr_node = lg->create_node(lg_ntype_op);
  bool is_new_var_chain = check_new_var_chain(lnidx_opr);

  //when #reg_0 at lhs, the register has not been created before, create it
  Node_pin reg_data_pin;
  Node_pin reg_qpin;
  if (is_register(lhs_vname)) {
    if (lnast->get_data(lhs).subs == 0)
      reg_qpin = setup_ref_node_dpin(lg, lhs);
    else
      reg_qpin = name2dpin[lhs_vname];

    reg_data_pin = reg_qpin.get_node().setup_sink_pin("din");
  }


  if (!is_new_var_chain) {
    name2dpin[lhs_name] = lg_opr_node.setup_driver_pin();
    lg_opr_node.get_driver_pin().set_name(lhs_name);
    setup_dpin_ssa(name2dpin[lhs_name], lhs_vname, lnast->get_subs(lhs));

    if (is_register(lhs_name))
      lg->add_edge(name2dpin[lhs_name], reg_data_pin);

    return lg_opr_node;
  }

  if (is_new_var_chain && vname2attr_dpin.find(lhs_vname) != vname2attr_dpin.end()) {
    auto aset_node = lg->create_node(Ntype_op::AttrSet);
    auto aset_chain_spin = aset_node.setup_sink_pin("chain");
    auto aset_ancestor_dpin = vname2attr_dpin[lhs_vname];
    lg->add_edge(aset_ancestor_dpin, aset_chain_spin);

    auto aset_vn_spin = aset_node.setup_sink_pin("name");
    auto aset_vn_dpin = lg_opr_node.get_driver_pin();
    lg->add_edge(aset_vn_dpin, aset_vn_spin);

    name2dpin[lhs_name] = aset_node.setup_driver_pin("Y"); // dummy_attr_set node now represent the latest variable
    lg_opr_node.get_driver_pin().set_name(lhs_name);
    aset_node.get_driver_pin("Y").set_name(lhs_name);
    //aset_node.get_driver_pin(1).set_name(lhs_name); // for debug purpose
    setup_dpin_ssa(name2dpin[lhs_name], lhs_vname, lnast->get_subs(lhs));
    vname2attr_dpin[lhs_vname] = aset_node.setup_driver_pin("chain");
    if (is_register(lhs_name))
      lg->add_edge(name2dpin[lhs_name], reg_data_pin);
  }
  return lg_opr_node;
}