void shooting::Move(real const& ti, model::mstate const& Xi, real const& tf, model::mstate & Xf) const {

	// Compute trajectory from t0 to tf
	Xf = myModel.ComputeTraj(ti, Xi, tf, 0);

}