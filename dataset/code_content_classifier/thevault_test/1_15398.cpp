SequenceFile::SequenceFile(NodeID nodeId,
                           DatabaseID dbId,
                           UserTypeID typeId,
                           SetID setId,
                           string path,
                           pdb::PDBLoggerPtr logger,
                           size_t pageSize) {
    this->nodeId = nodeId;
    this->dbId = dbId;
    this->typeId = typeId;
    this->setId = setId;
    this->file = nullptr;
    this->metaSize = sizeof(FileType) + sizeof(size_t);
    this->filePath = path;
    this->logger = logger;
    this->numFlushedPages = 0;
    this->pageSize = pageSize;
    logger->writeLn("SequenceFile: path:");
    logger->writeLn(filePath.c_str());
    this->openAll();
}