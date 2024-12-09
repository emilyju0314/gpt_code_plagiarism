MR_MAC_MIB::MR_MAC_MIB(Mac802_11mr *parent) :
	MPDUTxSuccessful(0),MPDUTxOneRetry(0),MPDUTxMultipleRetries(0),
	MPDUTxFailed(0), RTSFailed(0), ACKFailed(0), 
	MPDURxSuccessful(0), FrameReceives(0),  DataFrameReceives(0), CtrlFrameReceives(0), MgmtFrameReceives(0),
	FrameErrors(0), DataFrameErrors(0), CtrlFrameErrors(0), MgmtFrameErrors(0),
	FrameErrorsNoise(0), DataFrameErrorsNoise(0), CtrlFrameErrorsNoise(0), MgmtFrameErrorsNoise(0),	
	FrameDropSyn(0), DataFrameDropSyn(0), CtrlFrameDropSyn(0), MgmtFrameDropSyn(0),
	FrameDropTxa(0), DataFrameDropTxa(0), CtrlFrameDropTxa(0), MgmtFrameDropTxa(0),
	idleSlots(0), idle2Slots(0),
	VerboseCounters_(0)
{
	/*
	 * Bind the phy mib objects.  Note that these will be bound
	 * to Mac/802_11 variables
	 */
	
	parent->bind("RTSThreshold_", &RTSThreshold);
	parent->bind("ShortRetryLimit_", &ShortRetryLimit);
	parent->bind("LongRetryLimit_", &LongRetryLimit);
	parent->bind("VerboseCounters_", &VerboseCounters_);
}