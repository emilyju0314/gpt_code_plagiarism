int
IPNetwork::close()
{
	if (ssock_ >= 0) {
		(void)::close(ssock_);
		ssock_ = -1;
	}
	if (rsock_ >= 0) {
		(void)::close(rsock_);
		rsock_ = -1;
	}
	return (0);
}