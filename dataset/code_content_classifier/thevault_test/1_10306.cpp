ProblemData build_matrix(std::vector<const LinOp *> constraints, int var_length,
                         std::map<int, int> id_to_col,
                         std::map<int, int> param_to_size,
                         std::vector<int> constr_offsets) {
  ProblemData prob_data = init_data_tensor(param_to_size);

  /* Build matrix one constraint at a time */
  for (unsigned i = 0; i < constraints.size(); i++) {
    LinOp constr = *constraints[i];
    int vert_offset = constr_offsets[i];
    process_constraint(constr, prob_data, vert_offset, var_length, id_to_col);
  }
  return prob_data;
}