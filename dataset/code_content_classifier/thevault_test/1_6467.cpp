void
FullTcpAgent::finish()
{
	Tcl::instance().evalf("%s done", this->name());
}