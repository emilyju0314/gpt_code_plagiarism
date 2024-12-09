PartitionedFile::PartitionedFile(NodeID nodeId,
                                 DatabaseID dbId,
                                 UserTypeID typeId,
                                 SetID setId,
                                 string metaPartitionPath,
                                 vector<string> dataPartitionPaths,
                                 pdb::PDBLoggerPtr logger,
                                 size_t pageSize) {
    unsigned int i = 0;

    this->nodeId = nodeId;
    this->dbId = dbId;
    this->typeId = typeId;
    this->setId = setId;
    this->metaPartitionPath = metaPartitionPath;
    this->dataPartitionPaths = dataPartitionPaths;
    this->logger = logger;
    this->pageSize = pageSize;
    this->usingDirect = true;
    this->cleared = false;
    // Initialize meta data;
    this->metaData = make_shared<PartitionedFileMetaData>();
    this->metaData->setPageSize(pageSize);
    this->metaData->setNumFlushedPages(0);
    this->metaData->setVersion(0);
    this->metaData->setLatestPageId((unsigned int)(-1));
    pthread_mutex_init(&this->fileMutex, nullptr);
    PartitionMetaDataPtr curPartitionMetaData;
    for (i = 0; i < dataPartitionPaths.size(); i++) {
        curPartitionMetaData = make_shared<PartitionMetaData>(dataPartitionPaths.at(i), i);
        this->metaData->addPartition(curPartitionMetaData);
    }

    // Initialize FILE instances;
    this->metaFile = nullptr;
    for (i = 0; i < dataPartitionPaths.size(); i++) {
        this->dataFiles.push_back(nullptr);
        this->dataHandles.push_back(-1);
    }
    this->openAll();
    this->writeMeta();

    // Initialize the mutex;
}