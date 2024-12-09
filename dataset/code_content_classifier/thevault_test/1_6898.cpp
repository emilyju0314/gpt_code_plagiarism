void HttpInvalAgent::send(int realsize, AppData* data)
{
	Packet *pkt = allocpkt(data->size());
	hdr_inval *ih = hdr_inval::access(pkt);
	ih->size() = data->size();
	pkt->setdata(data);

	// Set packet size proportional to the number of invalidations
	hdr_cmn *ch = hdr_cmn::access(pkt);
	ch->size() = inval_hdr_size_ + realsize;
	Agent::send(pkt, 0);
}