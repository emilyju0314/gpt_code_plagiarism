void CSmsReceiver::StartListeningL()
    {
    // we can't handle several requests simultaneously
    if (IsActive())
        {
        User::Leave(KErrNotReady);
        }

    // just in case
    iReadSocket.Close();
    
    // open read socket
    User::LeaveIfError(iReadSocket.Open(iSocketServ,
                                        KSMSAddrFamily,
                                        KSockDatagram,
                                        KSMSDatagramProtocol));

    _LIT8(KMathTag, "#:!");

    // set match pattern
    TSmsAddr smsAddr; 
    smsAddr.SetSmsAddrFamily(ESmsAddrMatchText); 
    smsAddr.SetTextMatch(KMathTag); // put KNullDesC8 to catch all messages
    
    // use this to read the message from a certain port
    //smsAddr.SetSmsAddrFamily(ESmsAddrApplication8BitPort);
    //smsAddr.SetPort(16500); // GSM Application port from 16000 to 16999 
    
    // bind the socket
    User::LeaveIfError(iReadSocket.Bind(smsAddr));
    iBuf() = KSockSelectRead;
    
    Start();
    }