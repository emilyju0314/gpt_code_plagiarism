size_t SequenceFile::loadPage(FilePartitionID partitionId,
                              unsigned int pageSeqInPartition,
                              char* pageInCache,
                              size_t length) {
    if (this->file == nullptr) {
        return 0;
    }
    seekPage(pageSeqInPartition);
    return fread(pageInCache, sizeof(char), length, this->file);
}