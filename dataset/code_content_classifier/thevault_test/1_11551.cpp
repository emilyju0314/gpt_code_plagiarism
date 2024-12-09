std::string CSocket::localIPAddress()
    {
        static std::string localIPAddress;
        if (localIPAddress.empty())
        {
            try
            {
                boost::asio::io_service ioService;
                boost::asio::ip::udp::resolver resolver(ioService);
                boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "google.com", "");
                boost::asio::ip::udp::socket socket(ioService);
                socket.connect(*resolver.resolve(query));
                localIPAddress = socket.local_endpoint().address().to_string();
                socket.close();
            }
            catch (std::exception &e)
            {
                return ("127.0.0.1");
            }
        }
        return (localIPAddress);
    }