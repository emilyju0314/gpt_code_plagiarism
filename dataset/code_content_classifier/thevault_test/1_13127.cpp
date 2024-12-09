void XLeader::AddBroadcastWorker()
{
    XWorkerBroadcast* worker = new XWorkerBroadcast();
    bworkers.Add(worker);
}