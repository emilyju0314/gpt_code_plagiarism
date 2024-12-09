size_t PartitionedFile::loadPage(FilePartitionID partitionId,
                                 unsigned int pageSeqInPartition,
                                 char* pageInCache,
                                 size_t length) {
    if (usingDirect == true) {
        return loadPageDirect(partitionId, pageSeqInPartition, pageInCache, length);
    }
    FILE* curFile = this->dataFiles.at(partitionId);
    if (curFile == nullptr) {
        return 0;
    }
    if (pageSeqInPartition < this->getMetaData()->getPartition(partitionId)->getNumPages()) {
        seekPage(curFile, pageSeqInPartition);
        return fread(pageInCache, sizeof(char), length, curFile);
    } else {
        return (size_t)-1;
    }
}