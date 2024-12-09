INT32 Tcp::readInputData()
{
	// Prepare the input buffer
	const UINT16 max_length = 8192;
	UINT8 inBuffer[max_length];
	INT32 recvMsgSize = 0;

	// Ist die Verbindung offen?
	if (isOpen() == false)
	{
		ROS_ERROR("Tcp::readInputData: Connection is not open, aborting!");
		return -1;
	}
		
	// Read some data, if any
#ifdef _MSC_VER
	recvMsgSize = recv(m_connectionSocket, (char *)inBuffer, max_length, 0);
#else
	{
		int ret = -1;
		do {
			struct pollfd fd;

			fd.fd = m_connectionSocket; // your socket handler
			fd.events = POLLIN;
			ret = poll(&fd, 1, 1000); // 1 second for timeout
			switch (ret) {
				case -1:
					// Error
					break;
				case 0:
					// Timeout
					break;
				default:
					recvMsgSize = recv(m_connectionSocket, inBuffer, max_length, 0);
					break;
			}
			if (!m_readThread || m_readThread->m_threadShouldRun == false)
			{
				recvMsgSize = 0;
				break;
			}
		} while (ret == 0);
	}
#endif
	if (recvMsgSize < 0)
	{
		// Fehler
		ROS_ERROR("Tcp::readInputData: Failed to read data from socket, aborting!");
		ScopedLock lock(&m_socketMutex);
		closeSocket(); // otherwise the driver can terminate with broken pipe in next call to Tcp::write()
	}
	else if (recvMsgSize > 0)
	{
		// Erfolg
		printInfoMessage("Tcp::readInputData: Read " + toString(recvMsgSize) + " bytes from the connection.", m_beVerbose);
		
		// Falls eine Callback-Funktion definiert ist, rufe sie auf mit den
		// empfangenen Daten.
		if (m_readFunction != NULL)
		{
			// Die Daten an die Callback-Funktion uebergeben
			UINT32 length_uint32 = (UINT32)recvMsgSize;
			m_readFunction(m_readFunctionObjPtr, inBuffer, length_uint32);
		}
		else
		{
			// Es ist keine Callback-Funktion definiert, also die Daten im
			// lokalen Puffer speichern.
			for (INT32 i = 0; i < recvMsgSize; i++)
			{
				m_rxBuffer.push_back(inBuffer[i]);
			}
		}
	    m_last_tcp_msg_received_nsec = rosNanosecTimestampNow(); // timestamp in nanoseconds of the last received tcp message (or 0 if no message received)
		
	}
	else if (recvMsgSize == 0)
	{
		// Verbindungsabbruch
		ROS_ERROR("Tcp::readInputData: Read 0 bytes, connection is lost!");
		
		// Informieren?
		if (m_disconnectFunction != NULL)
		{
			m_disconnectFunction(m_disconnectFunctionObjPtr);
		}
		
		// Mutex setzen
		ScopedLock lock(&m_socketMutex);
		closeSocket(); // otherwise the driver can terminate with broken pipe in next call to Tcp::write()
		// m_connectionSocket = -1;	// Keine Verbindung mehr
	}
	
	return recvMsgSize;
}