void
FullTcpAgent::process_sack(hdr_tcp*)
{
	fprintf(stderr, "%f: FullTcpAgent(%s) Non-SACK capable FullTcpAgent received a SACK\n",
		now(), name());
	return;
}