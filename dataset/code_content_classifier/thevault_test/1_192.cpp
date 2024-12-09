TInt CSmsReceiver::RunError(TInt aError)
    {
    iObserver.HandleReceiveError(aError);
    return KErrNone;
    }