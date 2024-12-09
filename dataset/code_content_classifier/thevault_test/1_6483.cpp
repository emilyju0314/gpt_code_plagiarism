void
SackFullTcpAgent::reset()
{
	sq_.clear();			// no SACK blocks
	/* Fixed typo.  -M. Weigle 6/17/02 */
	sack_min_ = h_seqno_ = -1;	// no left edge of SACK blocks
	FullTcpAgent::reset();
}