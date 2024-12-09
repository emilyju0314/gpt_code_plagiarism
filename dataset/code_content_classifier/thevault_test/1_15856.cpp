int detail::sock_wrapper::recv_abortable(void *buf, std::size_t len, int flags)
{
	WSAEVENT io_event = 0;
	DWORD val = 0;

	try {
		io_event = CreateEvent(0, false, false, 0);
		abort_recv_event = CreateEvent(0, false, false, 0);
		if (!io_event || !abort_recv_event)
			throw sock_error("Cannot create event handle");

		WSABUF wb = {len, (char*)buf};

		WSAOVERLAPPED wo;
		wo.hEvent = io_event;

		WSAEVENT waitfor[2] = { io_event, abort_recv_event };

		DWORD fl = flags;

		if (WSARecv(sockhand, &wb, 1, &val, &fl, &wo, 0)!=0) {
			// I/O did not complete immediately, or we had an error

			if (WSAGetLastError()!=WSA_IO_PENDING) {
				CloseHandle(abort_recv_event);
				CloseHandle(io_event);
				throw sock_error_ex("Cannot receive from socket");
			}

			// I/O did not complete immediately. Wait for completion or abort

			switch (WSAWaitForMultipleEvents(2, waitfor, FALSE, WSA_INFINITE, FALSE)) {
			  case WSA_WAIT_EVENT_0:
					// I/O completed
					if (!WSAGetOverlappedResult(sockhand, &wo, &val, TRUE, &fl))
						throw sock_error_ex("Cannot receive from socket");
					break;

			  case WSA_WAIT_EVENT_0+1:
					// Abort request
					if (!CancelIo((HANDLE)sockhand))
						throw sock_error("Cannot cancel I/O request");
					break;

			  case WSA_WAIT_FAILED:
					throw sock_error_ex("Cannot wait for I/O completion");
					break;
			}
		}
	}
	catch (...) {
		if (abort_recv_event) {
			CloseHandle(abort_recv_event);
			abort_recv_event = 0;
		}
		if (io_event)
			CloseHandle(io_event);
		throw;
	}

	CloseHandle(abort_recv_event);
	CloseHandle(io_event);
	abort_recv_event = 0;
	return val;
}