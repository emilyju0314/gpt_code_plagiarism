int startSocket(){

	long WSAResult;
	WSADATA wsaData;
	WORD version;

	version = MAKEWORD(2, 2);

	//Start the Winsock DLL
	WSAResult = WSAStartup(version, &wsaData);

	//Creates the socket structure
	struct sockaddr_in address;
	int AddressSize = sizeof(address);

	//Creating the sockets
	SOCKET sock_listening;

	sock_listening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_family = AF_INET;
	address.sin_port = htons(24111);
	
	if (bind(sock_listening, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	bind(sock_listening, (SOCKADDR *)&address, sizeof(address));

	long successMsg;
	for (;;){
		ofstream logFile;
		logFile.open("C:\\Temp\\connection.txt");
		logFile << "Connection is ready!\n";
		if (sock_listening == accept(sock_listening, (SOCKADDR*)&address, &AddressSize)){
			logFile << "Connection has been found!\n";

			successMsg = send(sock_listening, "Welcome, connection has been made", 46, NULL);
		}

		logFile.close();
	}
}