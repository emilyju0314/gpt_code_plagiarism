void recvData(const ISocketPtr& sock, BinaryData& data)
    {
        BOOST_ASSERT(sock);
        // recv data size first
        size_t size = 0;
        BinaryData size_data(sizeof(size));
        sock->recvAll(size_data);
        memcpy(&size, size_data.toVoid(), sizeof(size));
        // recv all data
        data.resize(size);
        sock->recvAll(data);
    }