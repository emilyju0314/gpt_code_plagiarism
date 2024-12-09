NsObject* LmsAgent::iface2link (int iface)
{
	Tcl&	tcl = Tcl::instance();
	char	wrk[64];

	sprintf (wrk, "[%s set node_] ifaceGetOutLink %d", name (), iface);
	tcl.evalc (wrk);
	const char* result = tcl.result ();

#ifdef LMS_DEBUG
printf ("[iface2link] agent %s\n", result);
#endif

	NsObject* obj = (NsObject*)TclObject::lookup(result);
	return (obj);
}