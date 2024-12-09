void Code_gen::do_stmts(const mmap_lib::Tree_index& stmt_node_index) {
  fmt::print("node:stmts\n");
  if(lnast->is_leaf(stmt_node_index)) {return;} //check if no child node present

  auto curr_index = lnast->get_first_child(stmt_node_index);

  while(curr_index!=lnast->invalid_index()) {
    const auto& curr_node_type = lnast->get_type(curr_index);
    auto curlvl = curr_index.level;
    fmt::print("Processing stmt child {}:{} at level {} \n", lnast->get_name(curr_index), lnast->get_type(curr_index).debug_name(), curlvl);

    assert(!curr_node_type.is_invalid());
    if (curr_node_type.is_assign() || curr_node_type.is_dp_assign()) {
      do_assign(curr_index);
    } else if (curr_node_type.is_if()) {
      do_if(curr_index);
    } else if (curr_node_type.is_and()          ||
               curr_node_type.is_or()           ||
               curr_node_type.is_not()          ||
               curr_node_type.is_xor()          ||
               curr_node_type.is_logical_not()  ||
               curr_node_type.is_logical_and()  ||
               curr_node_type.is_logical_or()   ||
               curr_node_type.is_same()         ||
               curr_node_type.is_as()           ||
               curr_node_type.is_plus()         ||
               curr_node_type.is_minus()        ||
               curr_node_type.is_mult()         ||
               curr_node_type.is_div()          ||
               curr_node_type.is_lt()           ||
               curr_node_type.is_le()           ||
               curr_node_type.is_gt()           ||
               curr_node_type.is_ge()           ||
               curr_node_type.is_tuple_concat() ||
               curr_node_type.is_tuple_delete() ||
               curr_node_type.is_shift_left()   ||
               curr_node_type.is_shift_right()) {
      do_op(curr_index);
    } else if (curr_node_type.is_dot()) {
      do_dot(curr_index);
    } else if (curr_node_type.is_tuple()) {
      do_tuple(curr_index);
    } else if (curr_node_type.is_select()) {
      do_select(curr_index, "select");
    } else if (curr_node_type.is_bit_select()) {
      do_select(curr_index, "bit");
    } else if (curr_node_type.is_func_def()) {
      do_func_def(curr_index);
    } else if (curr_node_type.is_func_call()) {
      do_func_call(curr_index);
    } else if (curr_node_type.is_for()) {
      do_for(curr_index);
    } else if (curr_node_type.is_while()) {
      do_while(curr_index);
    } else if (curr_node_type.is_tposs()) {
      do_tposs(curr_index);
    }

    curr_index = lnast->get_sibling_next(curr_index);
  }
}