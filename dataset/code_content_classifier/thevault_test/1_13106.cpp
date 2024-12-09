bool XWorkerJob::AddJobRecord(XNNRecord * serverRecord)
{
    XList args;
    args.Add(this);
    args.Add(serverRecord);

    if (isInstantRun)
        XWorkerJob::RecordMeStatic(&args);
    else
        queue.EnqueueJob((void*)(char*)XWorkerJob::RecordMeStatic, &args);

    return true;
}