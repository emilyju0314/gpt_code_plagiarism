void Tcl::evalf(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vsprintf(bp_, fmt, ap);
	eval();
}