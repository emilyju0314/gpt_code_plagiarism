void TfrcAgent::sendmsg(int nbytes, const char* /*flags*/)
{
        if (nbytes == -1 && maxseq_ < MAXSEQ)
		advanceby(MAXSEQ - maxseq_);
        else if (size_ > 0) {
		int npkts = int(nbytes/size_);
		npkts += (nbytes%size_ ? 1 : 0);
		// maxqueue was added by Tom Phelan, to control the
		//   transmit queue from the application.
		if ((maxseq_ - seqno_) < maxqueue_) {
			advanceby(npkts);
		}
	}
}