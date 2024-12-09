int ScoreBoard::GetNextUnacked (int seqno)
{
	int i;
	if (!length_) {
		return (-1);
	} else if (seqno < SBN[(first_)%sbsize_].seq_no_ ||
		seqno >= SBN[(first_)%sbsize_].seq_no_+length_) {
		return (-1);
	} else {
		for (i=seqno; i<SBN[(first_)%sbsize_].seq_no_+length_; i++) {
			if (!SBNI.ack_flag_ && !SBNI.sack_flag_) {
				return (i);
			}
		}
	}
	return (-1);

}