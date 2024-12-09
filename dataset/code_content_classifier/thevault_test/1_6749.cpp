double Mac802_11Ext::txtime(double psz, int mod_scheme) {
	int datalen = (int) psz << 3;
	int DBPS = modulation_table[mod_scheme].NDBPS;

	// 802.11p
	if (phymib_.use_802_11a()) {
		datalen = datalen + 16 + 6; // 16 SYMBOL BITS, 6 TAIL BITS
	}
	int symbols = (int)(ceil((double)datalen/DBPS)); // PADDING BITS, FILL SYMBOl

	double t = phymib_.getHeaderDuration() + (double) symbols
			* phymib_.getSymbolDuration();
	return (t);
}