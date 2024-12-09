void XWorker::AddJobEnqueueFinished(XQueue* jobQueue)
{
    XList args;
    args.Add(this);

    XQueue& queueRun = jobQueue != NULL ? *jobQueue : queue;

    if (isInstantRun)
        XWorker::EnqueueFinished(&args);
    else
        queueRun.EnqueueJob((void*)(char*)XWorker::EnqueueFinished, &args);
}