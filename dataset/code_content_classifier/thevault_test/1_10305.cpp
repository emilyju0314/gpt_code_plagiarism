ProblemData build_matrix(std::vector<const LinOp *> constraints, int var_length,
                         std::map<int, int> id_to_col,
                         std::map<int, int> param_to_size, int num_threads) {
  /* Build matrix one constraint at a time */
  ProblemData prob_data = init_data_tensor(param_to_size);

  int vert_offset = 0;
  std::vector<std::pair<const LinOp*, int> > constraints_and_offsets;
  constraints_and_offsets.reserve(constraints.size());
  for (const LinOp* constraint : constraints) {
    auto pair = std::make_pair(constraint, vert_offset);
    constraints_and_offsets.push_back(pair);
    vert_offset += vecprod(constraint->get_shape());
  }

  // TODO: to get full parallelism, each thread should use its own ProblemData;
  // the ProblemData objects could be reduced afterwards (specifically
  // the V, I, and J arrays would be merged)
  #ifdef _OPENMP
  if (num_threads > 0) {
    omp_set_num_threads(num_threads);
  }
  #pragma omp parallel for
  #endif
  for (size_t i = 0; i < constraints_and_offsets.size(); ++i) {
    const std::pair<const LinOp*, int>& pair = constraints_and_offsets.at(i);
    const LinOp* constraint = pair.first;
    int vert_offset = pair.second;
    process_constraint(
      *constraint, prob_data, vert_offset, var_length, id_to_col);
  }
  return prob_data;
}