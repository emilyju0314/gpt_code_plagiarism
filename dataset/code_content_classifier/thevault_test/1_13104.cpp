bool XLeaderPS::Run(XConfig* config, DataDistributeBase* dataDistributor, XOptimizer* optimizer)
{
    CheckNTErrors(jworkers.count > 0, "No jworkers!");
    CheckNTErrors(cworkers.count > 0, "No cworkers!");
    CheckNTErrors(uworkers.count > 0, "No uworkers!");
    CheckNTErrors(bworkers.count > 0, "No bworkers!");
    CheckNTErrors(aworkers.count > 0, "No pworkers!");

    bool isToUpdate = (optimizer != NULL);
    int activeJobCount = 0;
    int* active = new int[jworkers.count];

    InitForRun();

    /* run models on job workers */
    activeJobCount = RunModel(config, dataDistributor, active);

    /* update the model on the server side */
    if (activeJobCount > 0 && isToUpdate)
        RunUpdate(config, optimizer, active);

    WaitForFinishing(active, isToUpdate);

    for (int i = 0; i < jworkers.count; i++) {
        XWorkerJob* worker = (XWorkerJob*)jworkers[i];
        worker->Clear();
    }

    delete[] active;

    return activeJobCount > 0;
}