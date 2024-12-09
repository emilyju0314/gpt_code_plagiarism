void* enterTheQueue(void* pdbWorkerQueueInstance) {
    PDBWorkerQueue* temp = static_cast<PDBWorkerQueue*>(pdbWorkerQueueInstance);
    temp->enter();
    return nullptr;
}