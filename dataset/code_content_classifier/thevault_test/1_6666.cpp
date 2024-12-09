void REMQueue::enque(Packet* pkt)
{
	hdr_cmn* ch = hdr_cmn::access(pkt);
	double qlen; 

	if (qib_) {
		remv_.v_count += ch->size();
	}
	else {
		++remv_.v_count;
	}

	double qlim = qib_ ? (qlim_*remp_.p_pktsize) : qlim_ ;

	q_ -> enque(pkt);
	bcount_ += ch->size();

	qlen = qib_ ? bcount_ : q_->length();

	if (qlen >= qlim) {
		q_->remove(pkt);
		bcount_ -= ch->size();
		drop(pkt);
	}
	else  {
		if (!markpkts_) {
			double u = Random::uniform(); 
			double pro = remv_.v_prob;
			if (qib_) {
				pro = remv_.v_prob*ch->size()/remp_.p_pktsize; 
			}
			if ( u <= pro ) {
				q_->remove(pkt);
				bcount_ -= ch->size();
				drop(pkt);
			}		    
		}
	}
	qlen = qib_ ? bcount_ : q_->length();
	curq_ = (int) qlen;
}