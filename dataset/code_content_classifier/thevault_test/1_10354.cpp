int mctpSockSendRecv(const std::vector<uint8_t>& requestMsg,
                     std::vector<uint8_t>& responseMsg)
{
    const char devPath[] = "\0mctp-mux";
    int returnCode = 0;

    int sockFd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
    if (-1 == sockFd)
    {
        returnCode = -errno;
        std::cerr << "Failed to create the socket : RC = " << sockFd << "\n";
        return returnCode;
    }
    std::cout << "Success in creating the socket : RC = " << sockFd
              << std::endl;

    struct sockaddr_un addr
    {
    };
    addr.sun_family = AF_UNIX;

    memcpy(addr.sun_path, devPath, sizeof(devPath) - 1);

    CustomFD socketFd(sockFd);
    int result = connect(socketFd(), reinterpret_cast<struct sockaddr*>(&addr),
                         sizeof(devPath) + sizeof(addr.sun_family) - 1);
    if (-1 == result)
    {
        returnCode = -errno;
        std::cerr << "Failed to connect to socket : RC = " << returnCode
                  << "\n";
        return returnCode;
    }
    std::cout << "Success in connecting to socket : RC = " << returnCode
              << std::endl;

    auto pldmType = MCTP_MSG_TYPE_PLDM;
    result = write(socketFd(), &pldmType, sizeof(pldmType));
    if (-1 == result)
    {
        returnCode = -errno;
        std::cerr << "Failed to send message type as pldm to mctp : RC = "
                  << returnCode << "\n";
        return returnCode;
    }
    std::cout << "Success in sending message type as pldm to mctp : RC = "
              << returnCode << std::endl;

    result = send(socketFd(), requestMsg.data(), requestMsg.size(), 0);
    if (-1 == result)
    {
        returnCode = -errno;
        std::cerr << "Write to socket failure : RC = " << returnCode << "\n";
        return returnCode;
    }
    std::cout << "Write to socket successful : RC = " << result << std::endl;

    // Read the response from socket
    ssize_t peekedLength = recv(socketFd(), nullptr, 0, MSG_TRUNC | MSG_PEEK);
    if (0 == peekedLength)
    {
        std::cerr << "Socket is closed : peekedLength = " << peekedLength
                  << "\n";
        return returnCode;
    }
    else if (peekedLength <= -1)
    {
        returnCode = -errno;
        std::cerr << "recv() system call failed : RC = " << returnCode << "\n";
        return returnCode;
    }
    else
    {
        // loopback response message
        std::vector<uint8_t> loopBackRespMsg(peekedLength);
        auto recvDataLength =
            recv(socketFd(), reinterpret_cast<void*>(loopBackRespMsg.data()),
                 peekedLength, 0);
        if (recvDataLength == peekedLength)
        {
            std::cout << "Total length:" << recvDataLength << std::endl;
            std::cout << "Loopback response message:" << std::endl;
            printBuffer(loopBackRespMsg);
        }
        else
        {
            std::cerr << "Failure to read peeked length packet : RC = "
                      << returnCode << "\n";
            std::cerr << "peekedLength: " << peekedLength << "\n";
            std::cerr << "Total length: " << recvDataLength << "\n";
            return returnCode;
        }

        // Confirming on the first recv() the Request bit is set in
        // pldm_msg_hdr struct. If set proceed with recv() or else, quit.
        auto hdr = reinterpret_cast<const pldm_msg_hdr*>(&loopBackRespMsg[2]);
        uint8_t request = hdr->request;
        if (request == PLDM_REQUEST)
        {
            std::cout << "On first recv(),response == request : RC = "
                      << returnCode << std::endl;
            ssize_t peekedLength =
                recv(socketFd(), nullptr, 0, MSG_PEEK | MSG_TRUNC);

            responseMsg.resize(peekedLength);
            recvDataLength =
                recv(socketFd(), reinterpret_cast<void*>(responseMsg.data()),
                     peekedLength, 0);
            if (recvDataLength == peekedLength)
            {
                std::cout << "Total length: " << recvDataLength << std::endl;
            }
            else
            {
                std::cerr << "Failure to read response length packet: length = "
                          << recvDataLength << "\n";
                return returnCode;
            }
        }
        else
        {
            std::cerr << "On first recv(),request != response : RC = "
                      << returnCode << "\n";
            return returnCode;
        }
    }
    returnCode = shutdown(socketFd(), SHUT_RDWR);
    if (-1 == returnCode)
    {
        returnCode = -errno;
        std::cerr << "Failed to shutdown the socket : RC = " << returnCode
                  << "\n";
        return returnCode;
    }

    std::cout << "Shutdown Socket successful :  RC = " << returnCode
              << std::endl;
    return PLDM_SUCCESS;
}