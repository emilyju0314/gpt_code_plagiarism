void Cprop::collapse_forward_always_pin0(Node &node, XEdge_iterator &inp_edges_ordered) {
  bool can_delete = true;

  auto op = node.get_type_op();

  for (auto &out : node.out_edges()) {
    /* if (out.driver.get_pid()) { */
    /*   can_delete = false; */
    /*   continue; */
    /* } */

    for (auto &inp : inp_edges_ordered) {
      /* if (inp.sink.get_pid()) { */
      /*   can_delete = false; */
      /*   continue; */
      /* } */
      TRACE(fmt::print("cprop forward_always pin:{} to pin:{}\n", inp.driver.debug_name(), out.sink.debug_name()));
      if (op == Ntype_op::Xor) {
        if (inp.driver.is_connected(out.sink)) {
          out.sink.del_driver(inp.driver);
        } else {
          out.sink.connect_driver(inp.driver);
        }
      } else {
        out.sink.connect_driver(inp.driver);
      }
    }
  }

  if (can_delete) {
    TRACE(fmt::print("cprop forward_always del_node node:{}\n", node.debug_name()));
    node.del_node();
  }
}