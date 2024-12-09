Node_pin Lnast_tolg::setup_ref_node_dpin(LGraph *lg, const Lnast_nid &lnidx_opd,
                                                      bool from_phi,     bool from_concat,
                                                      bool from_tupstrc, bool from_assign) {
  auto name  = lnast->get_sname(lnidx_opd); //name = ssa_name
  auto vname = lnast->get_vname(lnidx_opd);
  auto subs  = lnast->get_subs(lnidx_opd);
  I(!name.empty());

  // special case for register, when #x_-1 in rhs, return the reg_qpin, wname #x. Note this is not true for a phi-node.
  bool reg_existed = name2dpin.find(vname) != name2dpin.end();
  if (is_register(name) && !from_phi && reg_existed) {
    if (subs == -1) {
      return name2dpin.find(vname)->second;
    } else if (subs != 0){
      return name2dpin.find(name)->second;
    } else if (subs == 0 && name2dpin.find(name) != name2dpin.end()){
      return name2dpin.find(name)->second;
    } else {
      ; //the subs == 0 and this must be in lhs case, handle later in this function
    }
  }


  const auto it = name2dpin.find(name);
  if (it != name2dpin.end()) {
    auto node = it->second.get_node();
    auto op = it->second.get_node().get_type_op();

    // it's a scalar variable, just return the node pin
    if (op != Ntype_op::TupAdd)
      return it->second;

    if (op == Ntype_op::TupAdd && from_concat)
      return it->second;

    if (op == Ntype_op::TupAdd && from_tupstrc)
      return it->second;

    // when it's a tuple chain with multiple field -> not a scalar -> return the tuple chain for it
    if (op == Ntype_op::TupAdd && from_assign) {
      auto parent_node = node.setup_sink_pin("tuple_name").get_driver_node();
      auto parent_ntype = parent_node.get_type_op();
      if (parent_ntype == Ntype_op::TupAdd)
        return it->second;

      // case of $input as the assignment rhs
      if (parent_ntype == Ntype_op::TupRef && is_input(parent_node.setup_driver_pin().get_name()))
        return it->second;
    }

    // it's a tuple assignment TA
    if (op == Ntype_op::TupAdd && check_is_tup_assign(node)) {
      return it->second;
    }

    // return a connected TupGet if the ref node is a TupAdd but also a tuple-chain of a scalar
    auto tup_get = lg->create_node(Ntype_op::TupGet);
    auto tn_spin = tup_get.setup_sink_pin("tuple_name"); // tuple name
    auto field_pos_spin = tup_get.setup_sink_pin("position");   // field pos

    auto tn_dpin = it->second;
    auto field_pos_dpin = lg->create_node_const(Lconst(0)).setup_driver_pin(); //must be pos 0 as the case is "bar = a + 1", implicitly get a.0
    lg->add_edge(tn_dpin, tn_spin);
    lg->add_edge(field_pos_dpin, field_pos_spin);

    return tup_get.setup_driver_pin();
  }

  Node_pin node_dpin;
  if (is_output(name)) {
    ;
  } else if (is_input(name)) {
    node_dpin = lg->create_node(Ntype_op::TupRef).setup_driver_pin(); //later the node_type should change to TupGet and connected to $
    node_dpin.set_name(name.substr(0, name.size()-2));
    name2dpin[name] = node_dpin;
    return node_dpin;
  } else if (is_const(name)) {
    node_dpin = lg->create_node_const(Lconst(vname)).setup_driver_pin();
  } else if (is_register(name)) {
    auto reg_node = lg->create_node(Ntype_op::Sflop);
    node_dpin = reg_node.setup_driver_pin();
    setup_dpin_ssa(node_dpin, vname, -1);
    node_dpin.set_name(vname); //record #reg instead of #reg_0
    name2dpin[vname] = node_dpin;
    setup_clk(lg, reg_node);

    return node_dpin;
  } else if (is_err_var_undefined(name)) {
    node_dpin = lg->create_node(Ntype_op::CompileErr).setup_driver_pin();
  } else if (is_bool_true(name)) {
    node_dpin = lg->create_node_const(Lconst(1)).setup_driver_pin();
  } else if (is_bool_false(name)) {
    node_dpin = lg->create_node_const(Lconst(0)).setup_driver_pin();
  } else {
    return node_dpin; //return empty node_pin and trigger compile error
  }


  name2dpin[name] = node_dpin;  // for io and reg, the %$# identifier are still used in symbol table
  return node_dpin;
}