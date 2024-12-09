RapAgent::RapAgent() : Agent(PT_RAP_DATA), ipgTimer_(this), rttTimer_(this),
 	seqno_(0), sessionLossCount_(0), curseq_(0), ipg_(2.0), srtt_(2.0), 
	timeout_(2.0), lastRecv_(0), lastMiss_(0), prevRecv_(0), dctr_(0), 
	flags_(0), fixIpg_(0)
{
	bind("packetSize_", &size_);	// Default 512
	bind("seqno_", &seqno_);	// Default 0
	bind("sessionLossCount_", &sessionLossCount_); // Default 0

	bind("ipg_", &ipg_);		// Default 2 seconds
	bind("beta_", &beta_);	// Default 0.5
	bind("alpha_", &alpha_);	// Default 1.0

	bind("srtt_", &srtt_);	// Default 2 seconds
	bind("variance_", &variance_);// Default 0
	bind("delta_", &delta_);	// Default 0.5
	bind("mu_", &mu_);		// Default 1.2
	bind("phi_", &phi_);		// Default 4

	bind("timeout_", &timeout_);	// Default 2 seconds

	bind("overhead_", &overhead_); // Default 0

	bind("useFineGrain_", &useFineGrain_); // Default FALSE
	bind("kfrtt_", &kfrtt_);	// Default 0.9
	bind("kxrtt_", &kxrtt_);	// Default 0.01

	bind("debugEnable_", &debugEnable_);	// Default FALSE

	bind("rap_base_hdr_size_", &rap_base_hdr_size_);

	bind("dpthresh_", &dpthresh_);

	frtt_ = xrtt_ = srtt_;
}