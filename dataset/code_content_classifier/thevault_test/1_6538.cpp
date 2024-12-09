WebTrafPool::WebTrafPool() : 
	session_(NULL), nServer_(0), server_(NULL), nClient_(0), client_(NULL),
	nTcp_(0), nSink_(0), fulltcp_(0), recycle_page_(0)
{
	bind("fulltcp_", &fulltcp_);
	bind("recycle_page_", &recycle_page_);
	bind("dont_recycle_", &dont_recycle_);
	// Debo
	asimflag_=0;
	LIST_INIT(&tcpPool_);
	LIST_INIT(&sinkPool_);
	dbTcp_a = dbTcp_r = dbTcp_cr = 0;
}