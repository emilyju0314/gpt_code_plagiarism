ADP::ADP(MDART* mdart) {
	mdart_ = mdart;
	timer_ = new ADPDaupTimer(this);
	timerRx_ = new ADPDarqTimer(this);
	dht_ = new DHT();
	pckSeqNum_ = 0;
 }