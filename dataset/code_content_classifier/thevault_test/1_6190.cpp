_SocketThreadListMulti () : _local_addr (1111), _new_data(0), _new_data_written(0), _listProtect(1)
	{
		_ports = NULL;
		_number_o_ports = 0;
		_last_assigned = -1;
		_initialized = 0;
		_own_name = "__null";
	}