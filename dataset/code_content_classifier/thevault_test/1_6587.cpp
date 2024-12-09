void TcpAgent::sendmsg(int nbytes, const char* /*flags*/)
{
	if (nbytes == -1 && curseq_ <= TCP_MAXSEQ)
		curseq_ = TCP_MAXSEQ; 
	else
		curseq_ += (nbytes/size_ + (nbytes%size_ ? 1 : 0));
	send_much(0, 0, maxburst_);
}