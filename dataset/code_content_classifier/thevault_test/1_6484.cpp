int
SackFullTcpAgent::build_options(hdr_tcp* tcph)
{
	int total = FullTcpAgent::build_options(tcph);

        if (!rq_.empty()) {
                int nblk = rq_.gensack(&tcph->sa_left(0), max_sack_blocks_);
                tcph->sa_length() = nblk;
		total += (nblk * sack_block_size_) + sack_option_size_;
        } else {
                tcph->sa_length() = 0;
        }
	return (total);
}