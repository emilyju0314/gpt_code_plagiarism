void build_matrix_3(std::vector<LinOp*> constraints,
		    std::map<int, int> id_to_col,
		    std::vector<int> constr_offsets,
		    Rcpp::XPtr<ProblemData> prob_data){
  
  /* Function also verifies the offsets are valid */
  int num_rows = get_total_constraint_length(constraints, constr_offsets);
  prob_data->const_vec = std::vector<double> (num_rows, 0);
  prob_data->id_to_col = id_to_col;
  int horiz_offset  = 0;
  
  /* Build matrix one constraint at a time */
  for (unsigned i = 0; i < constraints.size(); i++){
    LinOp *constr = constraints[i];
#ifdef _R_DEBUG_
    Rcpp::Rcout << "Processing constraint " << i << std::endl;
#endif
    int vert_offset = constr_offsets[i];
    process_constraint(*constr, prob_data->V, prob_data->I, prob_data->J,
		       prob_data->const_vec, vert_offset,
		       prob_data->id_to_col, horiz_offset);
    prob_data->const_to_row[i] = vert_offset;
  }
}