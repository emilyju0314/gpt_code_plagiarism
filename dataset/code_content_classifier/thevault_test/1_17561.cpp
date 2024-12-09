void Tcp::closeSocket()
{
	// Close TCP socket
	if (isOpen() == true)
	{
		// Verbindung schliessen
#ifdef _MSC_VER
		::shutdown(m_connectionSocket, SD_BOTH);
		closesocket(m_connectionSocket);  // waere evtl. auch fuer Linux korrekt
#else
		::shutdown(m_connectionSocket, SHUT_RDWR);
		::close(m_connectionSocket);
#endif
		m_connectionSocket = -1;	// Keine Verbindung mehr
	}
}