double Mac802_11Ext::txtime(Packet *p) {
	struct hdr_cmn *ch = HDR_CMN(p);
	double t = ch->txtime();
	if (t < 0.0) {
		drop(p, "XXX");
		exit(1);
	}
	return t;
}