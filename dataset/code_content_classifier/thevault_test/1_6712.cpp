int FQ::update()
{
	int nactive = 0;
	for (int i = 0; i <= maxflow_; ++i) {
		Queue* q = fs_[i].q_;
		if (q != 0) {
			if (fs_[i].hol_ == 0) {
				Packet* p = q->deque();
				if (p != 0) {
					fs_[i].hol_ = p;
					++nactive;
				}
			} else
				++nactive;
		}
	}
	return (nactive);
}