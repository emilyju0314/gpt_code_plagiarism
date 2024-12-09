void UDPPythonClient::incomingData_ ()
{ 
  UDPdatagram UDPdataIN;

  struct sockaddr_in  inAddr;
  int_4               addrlen = sizeof(inAddr);

  UDPSocketLib::UDP_unblockSocket (UDPSocketLib::descriptorForServer(server_()));

  int hbytes = UDPService::readFrom ((unsigned char *)UDPdataIN.buffer, 
                                     MAX_UDP_DATA,
                                     0,
                                     &inAddr,
                                     addrlen);
  if (hbytes <= 0)
    return;
                                 //
                                 // create unique ID from inet addr 
                                 //
  int_u2   port     = ntohs( inAddr.sin_port );
  string   addrSTR  = inet_ntoa( inAddr.sin_addr );
  string   senderID = addrSTR + ":" + Stringize( port );


  //
  // Debug-
  //
  if (debugMask_ & UDPDBG_NETIN) {
      log_.message("UDP RECV: NumBytes= <"+Stringize(hbytes)+
                   ">;   from: " + senderID);
    //
    // prints raw UDP msg out in hex (cout)
    //
    if (debugMask_ & UDPDBG_DETAIL) 
      UDPService::debugUDPOutput_((unsigned char *)UDPdataIN.buffer, hbytes);
  }

  //
  // CLIENT-
  //
    M2Time CurrTime;
    lastMsgTime_ = CurrTime;

    // Interpret buffer
    GeoOpalMsg_Serialization_e ser = Serialization.value();
    GeoOpalMsgNetHdr msg(ser);
    StreamDataEncoding sde; 
    OpalTable MsgOT = msg.interpretBuffer(hbytes, (char*)UDPdataIN.buffer, sde);

    ///////////////RTS Left over, trying geoopalmsg, since it does everything for us
    //if (serialize_=="M2k") {
    //  IMemStream imem ((char *)UDPdataIN.buffer, hbytes);
    //  imem >> MsgOT;
    //} else if (serialize_=="P2") {
    //  OpalValue ov;
    //  P2TopLevelLoadOpal(ov, (char*)UDPdataIN.buffer);
    //  MsgOT = ov;
    //}

    ////stringTypeUse-
    ////tmp.deserialize((void *)UDPdataOUT.data());
    ////tmp.deserialize(str);
    //MsgOT.prettyPrint(cout);

    OutMsg.post(MsgOT);

    msgsRcvd_++;
    MsgsRcvd.post(msgsRcvd_);  

    if (status_ != UDPServer_UP) {
      GUIColour.post(UnStringize("{BG=\"green\",FG=\"black\"}", OpalTable));
      log_.warning ("UDP server(s) UP;  Message rcvd from: " + senderID);
      status_ = UDPServer_UP;
      Status.post(UDPServer_UP);
    }

  return;


}