BayFullTcpAgent::BayFullTcpAgent() : flags_(0),
	state_(TCPS_CLOSED), rq_(rcv_nxt_), last_ack_sent_(0), app_(0),
	delack_timer_(this)
{
	bind("segsperack_", &segs_per_ack_);
	bind("segsize_", &maxseg_);
	bind("tcprexmtthresh_", &tcprexmtthresh_);
	bind("iss_", &iss_);
	bind_bool("nodelay_", &nodelay_);
	bind_bool("data_on_syn_",&data_on_syn_);
	bind_bool("dupseg_fix_", &dupseg_fix_);
	bind_bool("dupack_reset_", &dupack_reset_);
	bind("interval_", &delack_interval_);
}