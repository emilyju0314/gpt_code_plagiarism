void CSmsReceiver::DoCancel()
    {
    iReadSocket.CancelIoctl();
    iState = ESmsIdle;
    }