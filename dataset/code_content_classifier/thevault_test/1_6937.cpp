RapAgent::~RapAgent()
{
//  	fprintf(stderr, "%g: rap agent %s(%d) stops.\n", 
//  		Scheduler::instance().clock(), name(), addr());
//  	Tcl::instance().eval("[Simulator instance] flush-trace");
	stop();
}