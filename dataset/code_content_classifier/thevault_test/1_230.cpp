size_t po8eConf::numChannels(po8e::channel_DataTypes x)
{
	size_t n = 0;
	for (auto &c : cards) {
		if (c->enabled()) {
			for (auto i=0; i<c->channel_size(); i++) {
				if (c->channel(i).data_type() == x) {
					n += 1;
				}
			}
		}
	}
	return n;
}