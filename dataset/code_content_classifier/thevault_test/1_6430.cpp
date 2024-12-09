int
TapAgent::linknet()
{
	int mode = net_->mode();
	int rchan = net_->rchannel();
	int wchan = net_->schannel();

	unlink();
	if (mode == O_RDONLY || mode == O_RDWR) {
		// reading enabled?
		if (rchan < 0) {
			fprintf(stderr,
		"TapAgent(%s): network %s not open for reading (mode:%d)\n",
			    name(), net_->name(), mode);
			return (TCL_ERROR);
		}
		link(rchan, TCL_READABLE);
		TDEBUG3("TapAgent(%s): linked sock %d as READABLE\n",
			name(), rchan);
	} else if (mode != O_WRONLY) {
		if (mode == -1) {
			fprintf(stderr,
			   "TapAgent(%s): Network(%s) not opened properly.\n",
				name(), net_->name());
			fprintf(stderr,
			   "(choose: readonly, readwrite, or writeonly)\n");
		} else {
			fprintf(stderr,
			    "TapAgent(%s): unknown mode %d in Network(%s)\n",
				name(), mode, net_->name());
		}
		return (TCL_ERROR);
	}

	if (mode == O_WRONLY || mode == O_RDWR) {
		// writing enabled?
		if (wchan < 0) {
			fprintf(stderr,
			"TapAgent(%s): network %s not open for writing\n",
			    name(), net_->name());
			return (TCL_ERROR);
		}
	}
	return (TCL_OK);
}