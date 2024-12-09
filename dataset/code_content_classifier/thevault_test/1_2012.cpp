static void pingpong(boost::asio::ip::tcp::socket &socket, bool verbose) {
	remote::RemoteDeviceMessage message;
	
	int errors = 0;
	for (int n = 0; n < 100 && !errors; n++) {
	
		if (verbose) {
			std::cout << "Iteration " << n << std::flush;
		}
	
		message.clear();
		message.header.operation = remote::RemoteDeviceMessage::Client_ping;
		message.header.messageSize = 4;
		message.resize();
		*((int *)&message.message[0]) = n;
		message.send(socket);
		
		if (verbose) {
			std::cout << " - sent " << std::flush;
		}
		
		message.clear();
		message.receive(socket);
		
		if (verbose) {
			std::cout << " - received " << std::flush;
		}
		
		if (message.header.operation == remote::RemoteDeviceMessage::Client_ping) {
			if (message.size() < 4) {
				std::cout << "FAILED\non iteration " << n << ", server returned message of size " 
					<< message.size() << " instead of size 4" << std::endl;
				++errors;
			}
			else if (*((int *)&message.message[0]) != ~n) {
				std::cout << "FAILED\non iteration " << n << ", server returned " << *((int *)&message.message[0]) <<
					" instead of " << ~n << "\n" << std::endl;
				++errors;
			}
			else {
				if (verbose) {
					std::cout << " - validated " << std::flush;
				}
			}
		}
		else {
			std::cout << "FAILED\non iteration " << n << ", server returned operation " 
				<< remote::RemoteDeviceMessage::toString(message.header.operation) << " instead of ::Client_ping\n" << std::endl;
				++errors;
		}
		if (verbose) {
			std::cout << std::endl;
		}
	}
	std::cout << "Test " << (errors ? "FAILED" : "Passed") << std::endl;
}