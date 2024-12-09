int UserType::addSet(string setName, SetID setId, size_t pageSize, size_t desiredSize, bool isMRU, bool isTransient, bool isSharedFFMatrixBlockSet) {
    if (this->sets->find(setId) != this->sets->end()) {
        this->logger->writeLn("UserType: set exists.");
        return -1;
    }
    string typePath;
    PartitionedFilePtr file;
    string metaFilePath = this->encodePath(this->metaPath, setId, setName);
    vector<string> dataFilePaths;
    unsigned int i;
    for (i = 0; i < this->dataPaths->size(); i++) {
        dataFilePaths.push_back(this->encodePath(this->dataPaths->at(i), setId, setName));
    }
    file = make_shared<PartitionedFile>(this->nodeId,
                                        this->dbId,
                                        this->id,
                                        setId,
                                        metaFilePath,
                                        dataFilePaths,
                                        this->logger,
                                        pageSize);

    SetPtr set = nullptr;
    LocalitySetReplacementPolicy policy = LRU;
    if (isMRU) {
        policy = MRU;
    }
    PersistenceType persistenceType = Persistent;
    if (isTransient) {
        persistenceType = Transient;
    }

    if (isSharedFFMatrixBlockSet) {
        std::cout << "****************We are creating a SharedFFMatrixBlockSet instance*********************" << std::endl;
    	set = make_shared<pdb::SharedFFMatrixBlockSet>(pageSize, logger, shm, nodeId, dbId, id, setId, setName, file, this->cache, JobData, policy, Write, TryCache, persistenceType, desiredSize);
    } else {
        set = make_shared<UserSet>(
          pageSize, logger, shm, nodeId, dbId, id, setId, setName, file, this->cache, JobData, policy, Write, TryCache, persistenceType, desiredSize);
    }
    if (set == 0) {
        this->logger->writeLn("UserType: Out of Memory.");
        return -1;
    }
    this->logger->writeLn("UserType: set added.");
    pthread_mutex_lock(&setLock);
    this->sets->insert(pair<SetID, SetPtr>(setId, set));
    pthread_mutex_unlock(&setLock);
    this->numSets++;
    return 0;
}