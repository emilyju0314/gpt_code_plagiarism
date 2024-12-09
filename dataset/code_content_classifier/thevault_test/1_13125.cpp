void XLeader::SetInstantRun(bool flag)
{
    for (int i = 0; i < jworkers.count; i++) {
        XWorkerJob * worker = (XWorkerJob*)jworkers.GetItem(i);
        worker->SetInstantRun(flag);
    }

    for (int i = 0; i < cworkers.count; i++) {
        XWorkerJob * worker = (XWorkerJob*)cworkers.GetItem(i);
        worker->SetInstantRun(flag);
    }

    for (int i = 0; i < uworkers.count; i++) {
        XWorkerJob * worker = (XWorkerJob*)uworkers.GetItem(i);
        worker->SetInstantRun(flag);
    }

    for (int i = 0; i < bworkers.count; i++) {
        XWorkerJob * worker = (XWorkerJob*)bworkers.GetItem(i);
        worker->SetInstantRun(flag);
    }

    for (int i = 0; i < aworkers.count; i++) {
        XWorker * worker = (XWorker*)aworkers.GetItem(i);
        worker->SetInstantRun(flag);
    }
}