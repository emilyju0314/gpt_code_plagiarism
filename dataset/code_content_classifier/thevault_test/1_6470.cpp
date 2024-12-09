int
FullTcpAgent::rcvseqinit(int seq, int dlen)
{
	return (seq + dlen + 1);
}