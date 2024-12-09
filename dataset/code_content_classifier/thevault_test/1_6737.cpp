void
Mac802_11mr::tx_resume()
{
	double rTime;
	assert(mhSend_.busy() == 0);
	assert(mhDefer_.busy() == 0);

	if(pktCTRL_) {
		/*
		 *  Need to send a CTS or ACK.
		 */
		mhDefer_.start(phymib_.getSIFS());
	} else if(pktRTS_) {
		if (mhBackoff_.busy() == 0) {
			/* Modifica Federico 9/12/2004 */
			/*rTime = (Random::random() % cw_) * phymib_.getSlotTime();
			mhDefer_.start( phymib_.getDIFS() + rTime);*/
		       
			mhBackoff_.start(cw_, is_idle(), phymib_.getDIFS());
			/*
			Fine modifica Federico 9/12/2004
			*/
		}
	} else if(pktTx_) {
		if (mhBackoff_.busy() == 0) {
			hdr_cmn *ch = HDR_CMN(pktTx_);
			struct hdr_mac802_11 *mh = HDR_MAC802_11(pktTx_);
			
			if ((u_int32_t) ch->size() < macmib_.getRTSThreshold()
			    || (u_int32_t) ETHER_ADDR(mh->dh_ra) == MAC_BROADCAST) {
				/* Modifica Federico 9/12/2004 */
				/*rTime = (Random::random() % cw_)
					* phymib_.getSlotTime();
				mhDefer_.start(phymib_.getDIFS() + rTime);*/
			       
			       
				mhBackoff_.start(cw_, is_idle(), phymib_.getDIFS());
			       
			       //Fine modifica Federico 9/12/2004
                        } else {
				mhDefer_.start(phymib_.getSIFS());
                        }
		}
	} else if(callback_) {
		Handler *h = callback_;
		callback_ = 0;
		h->handle((Event*) 0);
	}
	setTxState(MAC_IDLE);
}