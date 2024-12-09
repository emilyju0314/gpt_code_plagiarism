Node_pin Lnast_tolg::setup_tuple_ref(LGraph *lg, std::string_view ref_name) {
  auto it = name2dpin.find(ref_name);

  if (it != name2dpin.end())
    return it->second;

  if (is_input(ref_name)) {
    return create_inp_tg(lg, ref_name);
  }

  auto dpin = lg->create_node(Ntype_op::TupRef).setup_driver_pin();
  dpin.set_name(ref_name);
  name2dpin[ref_name] = dpin;
  return dpin;
}