int ScoreBoardRH::FakeSack (int last_ack, int num_dupacks)
{
	int i, sack_left, sack_right;
	int retran_decr = 0;

	//  If there is no scoreboard, create one.
	if (length_ == 0) {
		i = last_ack+1;
		SBNI.seq_no_ = i;
		SBNI.ack_flag_ = 0;
		SBNI.sack_flag_ = 0;
		SBNI.retran_ = 0;
		SBNI.snd_nxt_ = 0;
		SBNI.sack_cnt_ = 0;
		SBNI.rh_id_ = 0;
		first_ = i%SBSIZE;
		length_++;
		if (length_ >= SBSIZE) {
			printf ("Error, scoreboard too large (increase SBSIZE for more space)\n");
			exit(1);
		}
	}	

	//  Advance the left edge of the scoreboard.
	if (SBN[first_].seq_no_ <= last_ack) {
		for (i=SBN[(first_)%SBSIZE].seq_no_; i<=last_ack; i++) {
			//  Advance the ACK
			if (SBNI.seq_no_ <= last_ack) {
				ASSERT(first_ == i%SBSIZE);
				first_ = (first_+1)%SBSIZE; 
				length_--;
				ASSERT1(length_ >= 0);
				SBNI.ack_flag_ = 1;
				SBNI.sack_flag_ = 1;
				if (SBNI.retran_) {
					SBNI.retran_ = 0;
					SBNI.snd_nxt_ = 0;
					retran_decr++;
				}
				if (length_==0) 
					break;
			}
		}
		/*  Now create a new hole in the first position  */
		i=SBN[(first_)%SBSIZE].seq_no_;
		SBNI.ack_flag_ = 0;
		SBNI.sack_flag_ = 0;
		SBNI.retran_ = 0;
		SBNI.snd_nxt_ = 0;
		SBNI.rh_id_ = 0;
		SBNI.sack_cnt_ = num_dupacks;
	}

	sack_left = last_ack + 1;
	sack_right = sack_left + num_dupacks - 1;

	//  Create new entries off the right side.
	if (sack_right > SBN[(first_+length_+SBSIZE-1)%SBSIZE].seq_no_) {
		//  Create new entries
		for (i = SBN[(first_+length_+SBSIZE-1)%SBSIZE].seq_no_+1; i<sack_right; i++) {
			SBNI.seq_no_ = i;
			SBNI.ack_flag_ = 0;
			SBNI.sack_flag_ = 0;
			SBNI.retran_ = 0;
			SBNI.snd_nxt_ = 0;
			SBNI.sack_cnt_ = 0;
			SBNI.rh_id_ = 0;
			length_++;
			if (length_ >= SBSIZE) {
				printf ("Error, scoreboard too large (increase SBSIZE for more space)\n");
				exit(1);
			}
		}
	}
		
	for (i=SBN[(first_)%SBSIZE].seq_no_; i<sack_right; i++) {
		//  Check to see if this segment is now covered by the sack block
		if (SBNI.seq_no_ >= sack_left && SBNI.seq_no_ < sack_right) {
			if (! SBNI.sack_flag_) {
				SBNI.sack_flag_ = 1;
			}
			if (SBNI.retran_) {
				SBNI.retran_ = 0;
				retran_decr++;
			}
		}
	}

	/*  Now go through the whole scoreboard and update sack_cnt
	    on holes which still exist.  In this case the only possible 
	    case is the first hole.  */
        i=SBN[(first_)%SBSIZE].seq_no_;
	//  Check to see if this segment is a hole
	if (!SBNI.ack_flag_ && !SBNI.sack_flag_) {
		SBNI.sack_cnt_++;
	}

	return (retran_decr);
}