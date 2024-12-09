void CSmsSender::RunL()
    {
    if (iStatus == KErrNone)
        {
        // push first number from the numbers stack
        iNumbers->Delete(0);
        
        if (iNumbers->Count())
            {
            // send message to the next recepient
            DoSendSmsMessageL((*iNumbers)[0]);
            return;
            }
        else
            {
            iObserver.MessageSentComplete();
            }
        }
    else
        {
        iObserver.HandleError(iStatus.Int());
        }
    
    // cleanup
    delete iNumbers;
    iNumbers = NULL;
    delete iSmsMessage;
    iSmsMessage = NULL;
    iWriteSocket.Close();
    }