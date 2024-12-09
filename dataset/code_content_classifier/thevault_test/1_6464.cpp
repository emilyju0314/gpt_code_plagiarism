void
FullTcpAgent::bufferempty()
{
   	signal_on_empty_=FALSE;
	Tcl::instance().evalf("%s done_data", this->name());
}