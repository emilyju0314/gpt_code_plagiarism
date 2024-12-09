ProblemData build_matrix(std::vector< LinOp* > constraints,
                         std::map<int, int> id_to_col) {
	ProblemData prob_data;
	int num_rows = get_total_constraint_length(constraints);
	prob_data.const_vec = std::vector<double> (num_rows, 0);
	prob_data.id_to_col = id_to_col;
	int vert_offset = 0;
	int horiz_offset  = 0;

	/* Build matrix one constraint at a time */
	for (unsigned i = 0; i < constraints.size(); i++){
		LinOp constr = *constraints[i];
		process_constraint(constr, prob_data.V, prob_data.I, prob_data.J,
		                   prob_data.const_vec, vert_offset,
		                   prob_data.id_to_col, horiz_offset);
		prob_data.const_to_row[i] = vert_offset;
		vert_offset += constr.size[0] * constr.size[1];
	}
	return prob_data;
}