void HDLC::recvIncoming(Packet* p)
{
	// This pkt is coming from the network
	// check if pkt has error
	
	if (hdr_cmn::access(p)->error() > 0)
		drop(p);
	else {
		hdr_hdlc* hh = HDR_HDLC(p);
		switch (hh->fc_type_) {
		case HDLC_I_frame:
			recvIframe(p);
			break;
		case HDLC_S_frame:
			recvSframe(p);
			break;
		case HDLC_U_frame:
			recvUframe(p);
			break;
		default:
			fprintf(stderr, "Invalid HDLC control type\n");
			exit(1);
		}
	}
}