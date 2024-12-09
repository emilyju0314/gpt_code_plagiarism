void Receiver::start() {
	ClientHandler ch(rcvrQ);
	size_t port = stoi(localUrl.substr(localUrl.find(":") + 1, 4));
	SocketSystem ss;
	SocketListener sl(port, Socket::IP6);
	sl.start(ch);
	while (true)
		{
			HttpMessage msg = rcvrQ.deQ();
			std::cout << "\n\n  " + msg.findValue("toAddr") + " recvd message contents:\n  "
				+ msg.bodyString() + "\n  from " + msg.findValue("fromAddr");
			if (msg.bodyString() == "closeServer") break;
		}
}