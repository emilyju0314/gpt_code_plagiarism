size_t PartitionedFile::loadPageFromCurPos(FilePartitionID partitionId,
                                           unsigned int pageSeqInPartition,
                                           char* pageInCache,
                                           size_t length) {
    FILE* curFile = this->dataFiles.at(partitionId);
    if (curFile == nullptr) {
        return 0;
    }
    if (pageSeqInPartition < this->getMetaData()->getPartition(partitionId)->getNumPages()) {
        return fread(pageInCache, sizeof(char), length, curFile);
    } else {
        return (size_t)(-1);
    }
}