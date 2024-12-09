void Agent::recvBytes(int nbytes)
{
	if (app_)
		app_->recv(nbytes);	
}