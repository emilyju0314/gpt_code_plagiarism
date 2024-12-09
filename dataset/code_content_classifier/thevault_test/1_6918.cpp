int Sack1TcpAgent::is_sacked(hdr_tcp *tcph, int seqlo, int seqhi)
{
	int i, sleft, sright;
	for (i=0; i < tcph->sa_length(); i++) {
		sleft = tcph->sa_left(i);
		sright = tcph->sa_right(i);

		if ((sright > seqlo && sright <= seqhi) ||
		    (sleft >= seqlo && sleft < seqhi) ||
		    (sleft < seqlo && sright > seqhi)) {
			return TRUE;
		}
	}
	return FALSE;
}