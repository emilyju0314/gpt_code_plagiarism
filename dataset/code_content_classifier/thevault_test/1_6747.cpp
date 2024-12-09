void Mac802_11Ext::recv(Packet *p, Handler *h) {
	struct hdr_cmn *hdr = HDR_CMN(p);
	/*
	 * Sanity Check
	 */
	assert(initialized());

	if (hdr->direction() == hdr_cmn::DOWN) {
		if (MAC_DBG)
			log("FROM_IFQ", "");
		//			send(p, h); replaced by txc
		callback_=h;
		txc.handleMsgFromUp(p);
		return;
	} else {
		//the reception of a packet is moved to handleRXStart/EndIndication
		cout<<"logic error at recv, event sendUP"<<endl;
	}
}