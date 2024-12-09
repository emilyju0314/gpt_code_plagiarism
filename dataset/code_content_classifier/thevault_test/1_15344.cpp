void PartitionedFile::buildMetaDataFromMetaPartition(SharedMemPtr shm) {
    // parse the meta file
    /**
     *  Meta partition format:
     * - Metadata Size
     * - FileType
     * - Version
     * - PageSize
     * - NumFlushedPages
         * - LatestPageID (Add on Mar 21, 2016)
     * - NumPartitions
     * - PartitionID for 1st partition
     * - NumFlushedPages in 1st partition
     * - Length of the path to 1st partition
     * - Path to 1st partition
     * - PartitionID for 2nd partition
     * - NumFlushedPages in 2nd partition
     * - Length of the path to 2nd partition
     * - Path to 2nd partition
     * - ...
         * - pageId for the 1st page
         * - FilePartitionID for the 1st page
         * - PageSeqIdInPartition for the 1st page
         * - ...
	 *    * - ...
     * - DatabaseID of the shared page set
     * - TypeID of the shared page set
     * - SetID of the shared page set
     * - Number of shared pages
     * - ...
     * - PageId for the 1st page
     * - PartitionId for the 1st page
     * - PageSeqIdInPartition for the 1st page
     * - ...
     */
    // Open meta partition for reading
    if (this->openMeta() == false) {
        std::cout << "Fatal Error: PartitionedFile: Error: can't open meta partition." << std::endl;
        this->logger->error("Fatal Error: PartitionedFile: Error: can't open meta partition.");
        exit(-1);
    }
    // get meta partition size;
    fseek(this->metaFile, 0, SEEK_SET);
    size_t size;
    size_t sizeRead = fread((size_t*)(&(size)), sizeof(size_t), 1, this->metaFile);
    if (sizeRead == 0) {
        std::cout << "PartitionedFile: Read meta size failed" << std::endl;
        exit(-1);
    }
    // load meta partition to memory
    fseek(this->metaFile, sizeof(size_t), SEEK_SET);
    char* buf = (char*)calloc(size * sizeof(char), 1);
    if (buf == nullptr) {
        std::cout << "PartitionedFile.cc: Failed to allocate memory with size=" << size << std::endl;
        exit(1);
    }
    sizeRead = fread((void*)buf, sizeof(char), size, this->metaFile);
    if (sizeRead < size) {
        cout << "Metadata corrupted, please remove storage folders and try again...\n";
        this->logger->error(
            "Fatal Error: Metadata corrupted, please remove storage folders and try again...");
        exit(-1);
    }

    // create a meta data instance
    this->metaData = make_shared<PartitionedFileMetaData>();

    // parse file type
    char* cur = buf;
    cur = cur + sizeof(FileType);

    // parse and set version;
    unsigned short version = (unsigned short)(*(unsigned short*)cur);
    this->metaData->setVersion(version);
    cur = cur + sizeof(unsigned short);

    // parse and set pageSize;
    size_t pageSize = (size_t)(*(size_t*)cur);
    this->metaData->setPageSize(pageSize);
    this->pageSize = pageSize;
    std::cout << "Detected file with page size=" << pageSize << std::endl;
    cur = cur + sizeof(size_t);

    // parse and set numFlushed pages;
    unsigned int numFlushedPages = (unsigned int)(*(unsigned int*)cur);
    this->metaData->setNumFlushedPages(numFlushedPages);
    cur = cur + sizeof(unsigned int);

    // parse and set latestPageId;
    unsigned int latestPageId = (unsigned int)(*(unsigned int*)cur);
    this->metaData->setLatestPageId(latestPageId);
    cur = cur + sizeof(unsigned int);


    // parse numPartitions;
    unsigned int numPartitions = (unsigned int)(*(unsigned int*)cur);
    cur = cur + sizeof(unsigned int);
    PartitionMetaDataPtr curPartitionMeta;
    FilePartitionID partitionId;
    unsigned int numFlushedPagesInPartition;
    size_t pathLen;

    // parse and set partition meta data
    unsigned int i;
    for (i = 0; i < numPartitions; i++) {
        curPartitionMeta = make_shared<PartitionMetaData>();
        // parse and set partitionId
        partitionId = (FilePartitionID)(*(FilePartitionID*)cur);
        curPartitionMeta->setPartitionId(partitionId);
        cur = cur + sizeof(FilePartitionID);

        // parse and set numFlushedPages
        numFlushedPagesInPartition = (unsigned int)(*(unsigned int*)cur);
        curPartitionMeta->setNumPages(numFlushedPagesInPartition);
        cur = cur + sizeof(unsigned int);

        // parse len
        pathLen = (size_t)(*(size_t*)cur);
        cur = cur + sizeof(size_t);
        // parse string
        string partitionPath(cur);
        this->dataPartitionPaths.push_back(partitionPath);
        curPartitionMeta->setPath(partitionPath);
        this->metaData->addPartition(curPartitionMeta);
        cur = cur + pathLen;
    }

    PageID pageId;
    unsigned int pageSeqInPartition;
    // parse and set page index data
    for (i = 0; i < numFlushedPages; i++) {
        pageId = (PageID)(*(PageID*)cur);
        cur = cur + sizeof(PageID);
        partitionId = (FilePartitionID)(*(FilePartitionID*)cur);
        cur = cur + sizeof(FilePartitionID);
        pageSeqInPartition = (unsigned int)(*(unsigned int*)cur);
        cur = cur + sizeof(unsigned int);
        this->metaData->addPageIndex(pageId, partitionId, pageSeqInPartition);
    }

    //reconstruct shared page information
    DatabaseID dbId = (DatabaseID)(*(DatabaseID*)cur);
    cur = cur + sizeof(DatabaseID);
    UserTypeID typeId = (UserTypeID)(*(UserTypeID*)cur);
    cur = cur + sizeof(UserTypeID);
    SetID setId = (SetID)(*(SetID*)cur);
    cur = cur + sizeof(SetID);
    this->metaData->setSharedSetKey(dbId, typeId, setId);
    unsigned int numSharedPages = (unsigned int)(*(unsigned int*)cur);
    this->metaData->setNumSharedPages(numSharedPages);
    cur = cur + sizeof(unsigned int);

    for (i = 0; i < numSharedPages; i++) {
	pageId = (PageID)(*(PageID*)cur);
	cur = cur + sizeof(PageID);
        partitionId = (FilePartitionID)(*(FilePartitionID*)cur);
	cur = cur + sizeof(FilePartitionID);
	pageSeqInPartition = (unsigned int)(*(unsigned int*)cur);
	cur = cur + sizeof(unsigned int);
	this->metaData->addSharedPageIndex(pageId, partitionId, pageSeqInPartition);
    }
    free(buf);
}