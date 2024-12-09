BayFullTcpAgent::~BayFullTcpAgent()
{
  /*
   * not required any more
	register i;
	for (i = 0; i < NTIMER; i++)
		if (pending_[i])
			cancel(i);
  */
	rq_.clear();
}