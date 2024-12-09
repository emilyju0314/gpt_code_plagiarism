int
PcapFileNetwork::open(int /*mode*/, const char *filename)
{

	close();
	pcap_ = pcap_open_offline((char*) filename, errbuf_);
	if (pcap_ == NULL) {
		fprintf(stderr,
		  "pcap/file object (%s) couldn't open packet source %s: %s\n",
			name(), filename, errbuf_);
		return -1;
	}
	mode_ = O_RDONLY;	// sorry, that's all for now
	//
	// pcap only ever puts -1 in the pcap_fileno, which
	// isn't so convenient, so do this instead:
	// pfd_ = pcap_fileno(pcap_);
	pfd_ = fileno(pcap_file(pcap_));
	strncpy(srcname_, filename, sizeof(srcname_)-1);
	state_ = PNET_PSTATE_ACTIVE;
	return 0;
}