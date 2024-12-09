Packet* REMQueue::deque() 
{
	Packet *p = q_->deque();
	if (p != 0) {
		bcount_ -= hdr_cmn::access(p)->size ();
	}
	if (markpkts_) {
		double u = Random::uniform();
		if (p!=0) {
			double pro = remv_.v_prob;
			if (qib_) {
				int size = hdr_cmn::access(p)->size ();
				pro = remv_.v_prob*size/remp_.p_pktsize; 
			}
   		if ( u <= pro ) {
				hdr_flags* hf = hdr_flags::access(p);
				if(hf->ect() == 1) { 
					hf->ce() = 1; 
					pmark_++;
				}
			}
		}
	}
	double qlen = qib_ ? bcount_ : q_->length();
	curq_ = (int) qlen;
	return (p);
}