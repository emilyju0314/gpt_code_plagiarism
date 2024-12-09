_SocketThreadMultiBase (void) : _wakeup(0), _mutex(1), _reply_made(0)
    {
		_owner = NULL;
		_extern_buffer = NULL;
		_extern_length = 0;
		_extern_reply_buffer = NULL;
		_extern_reply_length = 0;
		_waiting = 0;
		_needs_reply = 0;
		_local_buffer_counter = 0;

		_port = 0;

		_available = 1;
		
		_remote_endpoint.invalidate();
		_socket_addr = NULL;

		_read_more = 0;
		_reply_preamble = 0;
    }