TInt CSmsSender::RunError(TInt aError)
    {
    iObserver.HandleError(aError);
    return KErrNone;
    }