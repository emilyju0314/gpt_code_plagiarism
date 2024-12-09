int
FullTcpAgent::build_options(hdr_tcp* tcph)
{
	int total = 0;
	if (ts_option_) {
		tcph->ts() = now();
		tcph->ts_echo() = recent_;
		total += ts_option_size_;
	} else {
		tcph->ts() = tcph->ts_echo() = -1.0;
	}
	return (total);
}