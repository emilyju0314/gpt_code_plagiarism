void InTCPThread::doLoop()
{
    initReader();

    while (!isStopped())
    {
        doLoopAction();
    }
}