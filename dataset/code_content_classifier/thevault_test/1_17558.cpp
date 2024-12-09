bool Tcp::open(std::string ipAddress, UINT16 port, bool enableVerboseDebugOutput)
{
	INT32 result;
	m_beVerbose = enableVerboseDebugOutput;
    m_last_tcp_msg_received_nsec = 0; // no message received
//	printInfoMessage("Tcp::open: Setting up input buffer with size=" + convertValueToString(requiredInputBufferSize) + " bytes.", m_beVerbose);
//	m_inBuffer.init(requiredInputBufferSize, m_beVerbose);
	
	printInfoMessage("Tcp::open: Opening connection.", m_beVerbose);
	s_wsa_auto_init_singleton.init();

	// Socket erzeugen
	m_connectionSocket = -1;	// Keine Verbindung
	{
		ScopedLock lock(&m_socketMutex);		// Mutex setzen
		m_connectionSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	}
	if (m_connectionSocket  < 0)
	{
        ROS_ERROR("Tcp::open: socket() failed, aborting.");
		return false;
	}

	// Socket ist da. Nun die Verbindung oeffnen.
	ROS_INFO_STREAM("sick_scan_xd: Tcp::open: connecting to " << ipAddress << ":"  << port << " ...");
	printInfoMessage("Tcp::open: Connecting. Target address is " + ipAddress + ":" + toString(port) + ".", m_beVerbose);
	
	struct sockaddr_in addr;
	struct hostent *server = 0;
	server = gethostbyname(ipAddress.c_str());
	memset(&addr, 0, sizeof(addr));     		// Zero out structure
	addr.sin_family = AF_INET;
	if (server != 0 && server->h_addr != 0)
	{
#ifdef _MSC_VER
		memcpy((char*)&addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
#else
		bcopy((char*)server->h_addr, (char*)&addr.sin_addr.s_addr, server->h_length);
#endif
	}
	else
	{
		addr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
	}
	addr.sin_port = htons(port);				// Host-2-Network byte order
#ifdef _MSC_VER
	result = connect(m_connectionSocket, (SOCKADDR*)(&addr), sizeof(addr));
#else
	result = connect(m_connectionSocket, (sockaddr*)(&addr), sizeof(addr));
#endif
	if (result < 0)
	{
		// Verbindungsversuch ist fehlgeschlagen
		std::string text = "Tcp::open: Failed to open TCP connection to " + ipAddress + ":" + toString(port) + ", aborting.";
#ifdef _MSC_VER
		char msgbuf[256] = "";
		int err = WSAGetLastError();
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),	msgbuf,	sizeof(msgbuf), NULL);
		text = text + " Connect error " + toString(WSAGetLastError()) + std::string(msgbuf);
#endif
		ROS_ERROR_STREAM("" << text);
		close(); // close socket
		return false;
	}

	printInfoMessage("Tcp::open: Connection established. Now starting read thread.", m_beVerbose);

	// Empfangsthread starten
	m_readThread = new SickThread<Tcp, &Tcp::readThreadFunction>("TcpRecvThread");
	m_readThread->run(this);
	
	ROS_INFO_STREAM("sick_scan_xd Tcp::open: connected to " << ipAddress << ":"  << port);
	printInfoMessage("Tcp::open: Done, leaving now.", m_beVerbose);

	return true;
}