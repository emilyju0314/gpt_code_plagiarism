void sendData(const ISocketPtr& sock, const BinaryData& data)
    {
        size_t size = data.size();
        if (size > 0)
        {
            BOOST_ASSERT(sock);

            // send data size first
            BinaryData size_data(sizeof(size));
            memcpy(size_data.toVoid(), &size, size_data.size());
            sock->send(size_data);

            // send main data
            sock->send(data);
        }
    }