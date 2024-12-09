int ScoreBoard::GetNextRetran()	// Returns sequence number of next pkt...
{
	int i;

	if (length_) {
		for (i=SBN[(first_)%sbsize_].seq_no_; 
		     i<SBN[(first_)%sbsize_].seq_no_+length_; i++) {
			if (!SBNI.ack_flag_ && !SBNI.sack_flag_ && !SBNI.retran_) {
				return (i);
			}
		}
	}
	return (-1);
}