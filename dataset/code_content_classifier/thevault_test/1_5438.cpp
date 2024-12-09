bool TCPTransportInterface::Receive(TCPChannelResource *pChannelResource, octet* receiveBuffer,
    uint32_t receiveBufferCapacity, uint32_t& receiveBufferSize, Locator_t& remoteLocator)
{
    bool success = false;

    { // lock scope
        if (!pChannelResource->IsAlive())
        {
            success = false;
        }
        else
        {
            success = true;
            try
            {
                std::unique_lock<std::recursive_mutex> scopedLock(pChannelResource->GetReadMutex());
                // Read the header
                //octet header[TCPHEADER_SIZE];
                TCPHeader tcp_header;
                asio::error_code ec;
                size_t bytes_received = read(*pChannelResource->getSocket(),
                    asio::buffer(&tcp_header, TCPHeader::getSize()),
                    transfer_exactly(TCPHeader::getSize()), ec);

                remoteLocator = pChannelResource->GetLocator();

                if (bytes_received != TCPHeader::getSize())
                {
                    if (bytes_received > 0)
                    {
                        logError(RTCP_MSG_IN, "Bad TCP header size: " << bytes_received << "(expected: : " << TCPHeader::getSize() << ")" << ec);
                    }
                    CloseTCPSocket(pChannelResource);
                    success = false;
                }
                else
                {
                    size_t body_size = tcp_header.length - static_cast<uint32_t>(TCPHeader::getSize());

                    if (body_size > receiveBufferCapacity)
                    {
                        logError(RTCP_MSG_IN, "Size of incoming TCP message is bigger than buffer capacity: "
                            << static_cast<uint32_t>(body_size) << " vs. " << receiveBufferCapacity << ". " <<
                            "The full message will be dropped.");
                        success = false;
                        // Drop the message
                        size_t to_read = body_size;
                        size_t read_block = receiveBufferCapacity;
                        uint32_t readed;
                        while (read_block > 0)
                        {
                            ReadBody(receiveBuffer, receiveBufferCapacity, &readed, pChannelResource, read_block);
                            to_read -= readed;
                            read_block = (to_read >= receiveBufferCapacity) ? receiveBufferCapacity : to_read;
                        }
                    }
                    else
                    {
                        logInfo(RTCP_MSG_IN, "Received RTCP MSG. Logical Port " << tcp_header.logicalPort);
                        success = ReadBody(receiveBuffer, receiveBufferCapacity, &receiveBufferSize, pChannelResource,
                            body_size);
                        //logInfo(RTCP_MSG_IN, " Received [ReadBody]");

                        if (GetConfiguration()->check_crc && !CheckCRC(tcp_header, receiveBuffer, receiveBufferSize))
                        {
                            logWarning(RTCP_MSG_IN, "Bad TCP header CRC");
                        }

                        if (tcp_header.logicalPort == 0)
                        {
                            //logInfo(RTCP_MSG_IN, " Receive [RTCP Control]  (" << receiveBufferSize+bytes_received
                            // << " bytes): " << receiveBufferSize << " bytes.");
                            ResponseCode responseCode =
                                mRTCPMessageManager->processRTCPMessage(pChannelResource, receiveBuffer, body_size);
                            if (responseCode != RETCODE_OK)
                            {
                                switch (responseCode)
                                {
                                    case RETCODE_INCOMPATIBLE_VERSION:
                                        {
                                            CloseOutputChannel(pChannelResource->mLocator);
                                            break;
                                        }
                                    default: // Ignore
                                        {
                                            CloseTCPSocket(pChannelResource);
                                            break;
                                        }
                                }
                            }
                            success = false;
                        }
                        else
                        {
                            IPLocator::setLogicalPort(remoteLocator, tcp_header.logicalPort);
                            logInfo(RTCP_MSG_IN, "[RECEIVE] From: " << remoteLocator \
                                << " - " << receiveBufferSize << " bytes.");
                        }
                    }
                }
            }
            catch (const asio::error_code& code)
            {
                if ((code == asio::error::eof) || (code == asio::error::connection_reset))
                {
                    // Close the channel
                    logInfo(RTCP_MSG_IN, "ASIO [RECEIVE]: " << code.message());
                    //pChannelResource->ConnectionLost();
                    CloseTCPSocket(pChannelResource);
                }
                success = false;
            }
            catch (const asio::system_error& error)
            {
                (void)error;
                // Close the channel
                logInfo(RTCP_MSG_IN, "ASIO [RECEIVE]: " << error.what());
                //pChannelResource->ConnectionLost();
                CloseTCPSocket(pChannelResource);
                success = false;
            }
        }
    }
    success = success && receiveBufferSize > 0;

    if (!success)
    {
        // TODO Manage errors, but don't remove the Channel Resource wihtout checks
        /*
        auto it = mChannelResources.find(IPLocator::toPhysicalLocator(pChannelResource->GetLocator()));
        if (it != mChannelResources.end())
        {
            mChannelResources.erase(it);
        }
        */
    }
    return success;
}