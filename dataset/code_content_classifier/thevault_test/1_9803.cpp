model::mstate shooting::Move(real const& ti, model::mstate const& Xi, real const& tf) const {

	// Compute trajectory from t0 to tf
	model::mstate X_tf = myModel.ComputeTraj(ti, Xi, tf, 0);

	return X_tf;

}