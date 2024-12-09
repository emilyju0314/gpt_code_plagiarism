bool Tcp::write(UINT8* buffer, UINT32 numberOfBytes)
{
	// Ist die Verbindung offen?
	if (isOpen() == false)
	{
		ROS_ERROR("Tcp::write: Connection is not open");
		return false;
	}
	INT32 bytesSent;
	bool result;
#ifdef _MSC_VER
	SOCKET* socketPtr = &m_connectionSocket;
	bytesSent = ::send(*socketPtr, (const char*)buffer, numberOfBytes, 0);
#else
	INT32* socketPtr = &m_connectionSocket;
	bytesSent = ::send(*socketPtr, buffer, numberOfBytes, 0);
#endif	
	// Sende Daten an das Socket
	if (bytesSent != (INT32)numberOfBytes)
	{
		printWarning("Tcp::write: Failed to send data to socket.");
		result = false;
	}
	else
	{
		// Erfolg
		printInfoMessage("Tcp::write: Sent " + toString(numberOfBytes) + " bytes to client.", m_beVerbose);
		result = true;
	}

	return result;
}