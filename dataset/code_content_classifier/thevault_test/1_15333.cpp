PartitionedFile::PartitionedFile(NodeID nodeId,
                                 DatabaseID dbId,
                                 UserTypeID typeId,
                                 SetID setId,
                                 string metaPartitionPath,
                                 pdb::PDBLoggerPtr logger) {

    this->nodeId = nodeId;
    this->dbId = dbId;
    this->typeId = typeId;
    this->setId = setId;
    this->metaPartitionPath = metaPartitionPath;
    this->logger = logger;
    this->cleared = false;


    // Initialize the mutex;
    pthread_mutex_init(&this->fileMutex, nullptr);
}