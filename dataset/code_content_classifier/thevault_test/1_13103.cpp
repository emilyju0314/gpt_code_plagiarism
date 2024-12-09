void XLeaderPS::WaitForFinishing(const int* activeJobWorkers, const int isToUpdate)
{
    int activeCount = 0;
    for (int i = 0; i < jworkers.count; i++) {
        if (activeJobWorkers[i] > 0) {
            XWorker* worker = (XWorker*)jworkers[i];
            worker->DequeueFinishedJob();
            activeCount++;
            CheckNTErrors(worker->GetFinishedNumInQueue() == 0, "Incorrect job number!");
        }
    }

    if (activeCount > 0 && isToUpdate) {
        for (int i = 0; i < cworkers.count; i++) {
            XWorker* worker = (XWorker*)cworkers[i];
            for (int j = 0; j < serverModel.paramNum * activeCount; j++)
                worker->DequeueFinishedJob();
            CheckNTErrors(worker->GetFinishedNumInQueue() == 0, "Incorrect job number!");
        }

        for (int i = 0; i < uworkers.count; i++) {
            XWorker* worker = (XWorker*)uworkers[i];
            for (int j = 0; j < serverModel.paramNum; j++)
                worker->DequeueFinishedJob();
            CheckNTErrors(worker->GetFinishedNumInQueue() == 0, "Incorrect job number!");
        }

        for (int i = 0; i < bworkers.count; i++) {
            XWorker* worker = (XWorker*)bworkers[i];
            for (int j = 0; j < serverModel.paramNum; j++)
                worker->DequeueFinishedJob();
            CheckNTErrors(worker->GetFinishedNumInQueue() == 0, "Incorrect job number!");
        }
    }
}