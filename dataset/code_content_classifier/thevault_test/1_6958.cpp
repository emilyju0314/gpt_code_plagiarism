void Agent::idle()
{
	if (app_)
		app_->resume();
}