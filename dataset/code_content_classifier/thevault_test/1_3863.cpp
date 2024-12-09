void build_matrix_2(std::vector< LinOp* > constraints,
		    std::map<int, int> id_to_col,
		    Rcpp::XPtr<ProblemData> prob_data) {
#ifdef _R_DEBUG_
  Rcpp::Rcout << "In Build_matrix_2" <<std::endl;    
#endif  

  int num_rows = get_total_constraint_length(constraints);
#ifdef _R_DEBUG_
  Rcpp::Rcout << "In Build_matrix_2 after length constraints " << num_rows <<std::endl;    
#endif  

  prob_data->const_vec = std::vector<double> (num_rows, 0);
#ifdef _R_DEBUG_
  Rcpp::Rcout << "Build_matrix_2 before id_to_col" <<std::endl;    
#endif  

  prob_data->id_to_col = id_to_col;
#ifdef _R_DEBUG_
  Rcpp::Rcout << "Build_matrix_2 after id_to_col" <<std::endl;    
#endif  

  int vert_offset = 0;
  int horiz_offset  = 0;

  /* Build matrix one constraint at a time */
  for (unsigned i = 0; i < constraints.size(); i++){
#ifdef _R_DEBUG_
    Rcpp::Rcout << "In Build_matrix_2 loop " << i << std::endl;    
#endif  
    LinOp *constr = constraints[i];
    process_constraint(*constr, prob_data->V, prob_data->I, prob_data->J,
		       prob_data->const_vec, vert_offset,
		       prob_data->id_to_col, horiz_offset);
    prob_data->const_to_row[i] = vert_offset;
    vert_offset += constr->size[0] * constr->size[1];
  }

}