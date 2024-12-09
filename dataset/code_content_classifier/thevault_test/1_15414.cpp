UserSet::UserSet(pdb::PDBLoggerPtr logger,
                 SharedMemPtr shm,
                 NodeID nodeId,
                 DatabaseID dbId,
                 UserTypeID typeId,
                 SetID setId,
                 string setName,
                 PageCachePtr pageCache,
                 LocalityType localityType,
                 LocalitySetReplacementPolicy policy,
                 OperationType operation,
                 DurabilityType durability,
                 PersistenceType persistence,
                 size_t pageSize,
                 size_t desiredSize,
		 bool isShared)
    : LocalitySet(localityType, policy, operation, durability, persistence, desiredSize, isShared) {
    this->isShared = isShared;
    this->pageSize = pageSize;
    this->logger = logger;
    this->shm = shm;
    this->nodeId = nodeId;
    this->dbId = dbId;
    this->typeId = typeId;
    this->setId = setId;
    this->setName = setName;
    this->pageCache = pageCache;
    this->inputBufferPage = nullptr;
    this->lastFlushedPageId = (unsigned int)(-1);
    this->dirtyPagesInPageCache = new unordered_map<PageID, FileSearchKey>();
    pthread_mutex_init(&this->dirtyPageSetMutex, nullptr);
    pthread_mutex_init(&this->addBytesMutex, nullptr);
    this->isPinned = false;
    this->numPages = 0;

}