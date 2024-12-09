Unit WorkerManager::getBuilder(Building & b, bool setJobAsBuilder) const
{
    Unit builderWorker = getClosestMineralWorkerTo(Util::GetPosition(b.finalPosition));

    // if the worker exists (one may not have been found in rare cases)
    if (builderWorker.isValid() && setJobAsBuilder)
    {
        m_workerData.setWorkerJob(builderWorker, WorkerJobs::Build, b.builderUnit);	// b.builderUnit is actually not used
    }

    return builderWorker;
}