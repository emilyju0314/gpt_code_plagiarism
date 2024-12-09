void YARP_unsafe_printf(char *format,...)
{
	va_list arglist;
	va_start(arglist,format);
	vprintf(format,arglist);
	va_end(arglist);
}