double TcpAgent::decrease_param()
{
	double decrease;
	// OLD:
	// decrease = linear(log(cwnd_), log(low_window_), 0.5, log(high_window_), high_decrease_);
	// NEW (but equivalent):
        decrease = hstcp_.dec1 + log(cwnd_) * hstcp_.dec2;  
	return decrease;
}