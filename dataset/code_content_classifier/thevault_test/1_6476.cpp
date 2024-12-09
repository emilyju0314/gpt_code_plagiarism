int
FullTcpAgent::send_allowed(int seq)
{
        int win = window() * maxseg_;
        int topwin = curseq_; // 1 seq number past the last byte we can send

        if ((topwin > highest_ack_ + win) || infinite_send_)
                topwin = highest_ack_ + win; 

	return (seq < topwin);
}