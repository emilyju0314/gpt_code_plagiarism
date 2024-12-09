void
TcpAgent::set_initial_window()
{
	if (syn_ && delay_growth_) {
		cwnd_ = 1.0; 
		syn_connects_ = 0;
	} else
		cwnd_ = initial_window();
}