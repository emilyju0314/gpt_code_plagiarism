void CSmsReceiver::RunL()
    {
    if (iStatus == KErrNone)
        {
        if (iState == ESmsListening)
            {
            // allocate SMS buffer
            CSmsBuffer* buffer = CSmsBuffer::NewL();
            CleanupStack::PushL(buffer);
            
            // create new incoming message, pass ownership of the buffer!
            CSmsMessage* message = CSmsMessage::NewL(iFs, 
                                                     CSmsPDU::ESmsDeliver, 
                                                     buffer);
            CleanupStack::Pop(buffer);
            CleanupStack::PushL(message);

            // open socket read stream
            RSmsSocketReadStream readStream(iReadSocket);
            CleanupClosePushL(readStream);

            // read message
            message->InternalizeL(readStream);
            CleanupStack::PopAndDestroy(&readStream);
            
            TPtrC number = message->ToFromAddress();
            // extract the message body
            HBufC* body = HBufC::NewLC(message->Buffer().Length());
            TPtr bodyPtr(body->Des());
            message->Buffer().Extract(bodyPtr, 0, message->Buffer().Length());

            iObserver.MessageReceived(number, *body);
            CleanupStack::PopAndDestroy(2, message); // body, message
            
            // notify system about successful receiving
            iReadSocket.Ioctl(KIoctlReadMessageSucceeded, iStatus, 
                              NULL, KSolSmsProv);
            iState = ESmsSystemNotyfing;
            SetActive();
            }
        else
            {
            Start();
            }
        }
    else
        {
        iObserver.HandleReceiveError(iStatus.Int());
        }
    }