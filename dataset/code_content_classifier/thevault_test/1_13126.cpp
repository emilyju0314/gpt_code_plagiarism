void XLeader::AddCollectWorker(DATA_COLLECT_TYPE mode)
{
    XWorkerCollect * worker = new XWorkerCollect();
    worker->SetCollectMode(mode);
    cworkers.Add(worker);
}