int ScoreBoardRH::GetNextRetran()	// Returns sequence number of next pkt...
{
	int i;

	if (length_) {
		for (i=SBN[(first_)%SBSIZE].seq_no_; 
		     i<SBN[(first_)%SBSIZE].seq_no_+length_; i++) {
			if (!SBNI.ack_flag_ && !SBNI.sack_flag_ && !SBNI.retran_
			    && (SBNI.sack_cnt_ >= *numdupacks_)) {
				return (i);
			}
		}
	}
	return (-1);
}