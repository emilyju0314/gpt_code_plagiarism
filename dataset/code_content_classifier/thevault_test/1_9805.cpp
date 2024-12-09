model::mstate shooting::Move(real const& tf) const {
	int numParam = data->numParam;

	// Initial model state
	model::mstate X0 = data->X[0];
	for (int i = 0; i<2 * data->dim; i++)	X0[i] = data->tab_param[i];

	// initial time
	real t0 = data->time[0];
	if (data->mode_t[0] == model::FIXED) {
		t0 = data->time[0];
	}
	else {
		t0 = data->tab_param[2 * data->numMulti*data->dim];
	}
	// final time
	real t_f, tf_traj;
	if (data->mode_t[data->numMulti] == model::FIXED) {
		tf_traj = data->time[data->numMulti];
	}
	else {
		tf_traj = data->tab_param[numParam - 1];
	}
	t_f = tf_traj;
	if (tf >= t0 && tf <= tf_traj) {
		t_f = tf;
	}

	// Get the timeline
	std::vector<real> timeLine(data->numMulti + 1);
	ComputeTimeLine(data->tab_param, timeLine);

	// Find which piece of trajectory include t_f
	real t1, t2;
	int iter = 0;
	t1 = timeLine[0];
	t2 = timeLine[1];
	while (t2<t_f) {
		iter += 1;
		t1 = timeLine[iter];
		t2 = timeLine[iter + 1];
	}
	// Compute trajectory from t1 to tf
	model::mstate X1 = X0;
	int index = 2 * iter*data->dim;
	if (iter > 0 && iter < data->numMulti) {
		// update data
		for (int i = 0; i<2 * data->dim; i++)	X1[i] = data->tab_param[index + i];
	}

	model::mstate X_tf = Move(t1, X1, t_f);

	return X_tf;

}