void XWorker::AddJobDequeueFinished(XQueue* jobQueue)
{
    XList args;
    args.Add(this);

    XQueue& queueRun = jobQueue != NULL ? *jobQueue : queue;

    if (isInstantRun)
        XWorker::DequeueFinished(&args);
    else
        queueRun.EnqueueJob((void*)(char*)XWorker::DequeueFinished, &args);

}