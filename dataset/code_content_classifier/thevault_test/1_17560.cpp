void Tcp::close()
{
	printInfoMessage("Tcp::close: Closing Tcp connection.", m_beVerbose);

	// Dem Lese-Thread ein Ende signalisieren
	if(m_readThread)
		m_readThread->m_threadShouldRun = false;
	// Close TCP socket
	if (isOpen() == true)
	{
		closeSocket();
	}
	else
	{
		printInfoMessage("Tcp::close: Nothing to do - no open connection? Aborting.", m_beVerbose);
	}
    // Thread stoppen
	if(m_readThread)
		stopReadThread();
	m_last_tcp_msg_received_nsec = 0; // no message received

	printInfoMessage("Tcp::close: Done - Connection is now closed.", m_beVerbose);
}