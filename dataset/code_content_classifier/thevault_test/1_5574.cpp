bool RedisClient::subscribe(const std::string& channel,
                                const OnRedisSubscribeResponseCallback& responseCallback,
                                const OnRedisSubscribeCallback& callback)
    {
        _stop = false;

        if (!_socket) return false;

        std::stringstream ss;
        ss << "*2\r\n";
        ss << writeString("SUBSCRIBE");
        ss << writeString(channel);

        bool sent = _socket->writeBytes(ss.str(), nullptr);
        if (!sent)
        {
            return false;
        }

        // Wait 1s for the response
        auto pollResult = _socket->isReadyToRead(-1);
        if (pollResult == PollResultType::Error)
        {
            return false;
        }

        // build the response as a single string
        std::stringstream oss;

        // Read the first line of the response
        auto lineResult = _socket->readLine(nullptr);
        auto lineValid = lineResult.first;
        auto line = lineResult.second;
        oss << line;

        if (!lineValid) return false;

        // There are 5 items for the subscribe reply
        for (int i = 0; i < 5; ++i)
        {
            auto lineResult = _socket->readLine(nullptr);
            auto lineValid = lineResult.first;
            auto line = lineResult.second;
            oss << line;

            if (!lineValid) return false;
        }

        responseCallback(oss.str());

        // Wait indefinitely for new messages
        while (true)
        {
            if (_stop) break;

            // Wait until something is ready to read
            int timeoutMs = 10;
            auto pollResult = _socket->isReadyToRead(timeoutMs);
            if (pollResult == PollResultType::Error)
            {
                return false;
            }

            if (pollResult == PollResultType::Timeout)
            {
                continue;
            }

            // The first line of the response describe the return type,
            // => *3 (an array of 3 elements)
            auto lineResult = _socket->readLine(nullptr);
            auto lineValid = lineResult.first;
            auto line = lineResult.second;

            if (!lineValid) return false;

            int arraySize;
            {
                std::stringstream ss;
                ss << line.substr(1, line.size() - 1);
                ss >> arraySize;
            }

            // There are 6 items for each received message
            for (int i = 0; i < arraySize; ++i)
            {
                auto lineResult = _socket->readLine(nullptr);
                auto lineValid = lineResult.first;
                auto line = lineResult.second;

                if (!lineValid) return false;

                // Messages are string, which start with a string size
                // => $7 (7 bytes)
                int stringSize;
                std::stringstream ss;
                ss << line.substr(1, line.size() - 1);
                ss >> stringSize;

                auto readResult = _socket->readBytes(stringSize, nullptr, nullptr);
                if (!readResult.first) return false;

                if (i == 2)
                {
                    // The message is the 3rd element.
                    callback(readResult.second);
                }

                // read last 2 bytes (\r\n)
                char c;
                _socket->readByte(&c, nullptr);
                _socket->readByte(&c, nullptr);
            }
        }

        return true;
    }