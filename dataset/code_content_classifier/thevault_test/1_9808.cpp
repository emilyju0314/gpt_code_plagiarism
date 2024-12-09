void shooting::GetParameters(std::vector<real> & paramVector) const {
	paramVector.resize(data->numParam);
	for (int k = 0; k<data->numParam; k++) {
		paramVector[k] = data->tab_param[k];
	}
}