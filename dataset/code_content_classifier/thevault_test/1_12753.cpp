void CMultiPoleModel2::getState(CState *state)
{
	///resets the state object
	CEnvironmentModel::getState(state);

	// Set the 4 internal state variables to the 
	// continuous state variables of the model state
	state->setContinuousState(0, x);
	state->setContinuousState(1, x_dot);
	state->setContinuousState(2, theta);
	state->setContinuousState(3, theta_dot);
}