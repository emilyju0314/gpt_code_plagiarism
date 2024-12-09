void XLeader::InitForRun()
{
    serverModel.InitForRun();

    for (int i = 0; i < jworkers.count; i++) {
        XModel* model = ((XWorkerJob*)jworkers[i])->GetModel();
        model->InitForRun();
    }

    XList workers;
    workers.AddList(&jworkers);
    workers.AddList(&cworkers);
    workers.AddList(&uworkers);
    workers.AddList(&bworkers);
    workers.AddList(&aworkers);

    for (int i = 0; i < workers.count; i++) {
        XWorker* worker = (XWorker*)workers[i];
        CheckNTErrors(worker->IsEmpty(), "Something is wrong with the finishedQueue!");
    }
}