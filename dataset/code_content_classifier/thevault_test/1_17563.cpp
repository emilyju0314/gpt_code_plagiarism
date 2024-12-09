int SickScanCommonTcp::sendSOPASCommand(const char *request, std::vector<unsigned char> *reply, int cmdLen, bool wait_for_reply)
  {
    int sLen = 0;
    int msgLen = 0;
    int preambelCnt = 0;
    bool cmdIsBinary = false;

    if (request != NULL)
    {
      sLen = cmdLen;
      preambelCnt = 0; // count 0x02 bytes to decide between ascii and binary command
      if (sLen >= 4)
      {
        for (int i = 0; i < 4; i++)
        {
          if (request[i] == 0x02)
          {
            preambelCnt++;
          }
        }
      }

      if (preambelCnt < 4)
      {
        cmdIsBinary = false;
      }
      else
      {
        cmdIsBinary = true;
      }
      if (cmdIsBinary == false)
      {
        msgLen = strlen(request);
      }
      else
      {
        int dataLen = 0;
        for (int i = 4; i < 8; i++)
        {
          dataLen |= ((unsigned char) request[i] << (7 - i) * 8);
        }
        msgLen = 8 + dataLen + 1; // 8 Msg. Header + Packet + CRC
      }
      if (getEmulSensor())
      {
        emulateReply((UINT8 *) request, msgLen, reply);
      }
      else
      {
        bool debugBinCmd = false;
        if (debugBinCmd)
        {
          printf("=== START HEX DUMP ===\n");
          for (int i = 0; i < msgLen; i++)
          {
            unsigned char *ptr = (UINT8 *) request;
            printf("%02x ", ptr[i]);
          }
          printf("\n=== END HEX DUMP ===\n");
        }
        if (!m_nw.sendCommandBuffer((UINT8 *) request, msgLen))
        {
          ROS_ERROR("## ERROR in sendSOPASCommand(): sendCommandBuffer failed");
          return ExitError;
        }
      }
    }
    if(!wait_for_reply)
    {
      return ExitSuccess;
    }

    // Set timeout in 5 seconds
    const int BUF_SIZE = 65536;
    char buffer[BUF_SIZE];
    int bytes_read;
    // !!!
    if (getEmulSensor())
    {

    }
    else
    {
      std::vector<std::string> response_keywords = { sick_scan::SickScanMessages::getSopasCmdKeyword((uint8_t*)request, msgLen) }; 
      if (readWithTimeout(getReadTimeOutInMs(), buffer, BUF_SIZE, &bytes_read, response_keywords) == ExitError)
      {
#if defined __ROS_VERSION && __ROS_VERSION == 1
          ROS_INFO_THROTTLE(1.0, "sendSOPASCommand: no full reply available for read after %d ms", getReadTimeOutInMs());
#else
          ROS_WARN_STREAM("sendSOPASCommand: no full reply available for read after " << getReadTimeOutInMs() << " ms");
#endif
#ifdef USE_DIAGNOSTIC_UPDATER
          if(diagnostics_ && rosOk())
            diagnostics_->broadcast(getDiagnosticErrorCode(),
                               "sendSOPASCommand: no full reply available for read after timeout.");
#endif
        return ExitError;
      }


      if (reply)
      {
        reply->resize(bytes_read);

        std::copy(buffer, buffer + bytes_read, &(*reply)[0]);
      }
    }
    return ExitSuccess;
  }