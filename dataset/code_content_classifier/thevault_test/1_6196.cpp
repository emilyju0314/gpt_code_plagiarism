_SocketThreadListMulti::~_SocketThreadListMulti (void)
{
	if (_ports != NULL) delete[] _ports;
	_ports = NULL;
	_number_o_ports = 0;
	_last_assigned = -1;
	_initialized = 0;
}