real *shooting::GetParameters() const {
	real *param = new real[data->numParam];
	for (int k = 0; k<data->numParam; k++) {
		param[k] = data->tab_param[k];
	}

	return param;
}