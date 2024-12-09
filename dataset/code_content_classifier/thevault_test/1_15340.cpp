size_t PartitionedFile::loadPageDirect(FilePartitionID partitionId,
                                       unsigned int pageSeqInPartition,
                                       char* pageInCache,
                                       size_t length) {
    int handle = this->dataHandles.at(partitionId);
    size_t ret;
    if (handle < 0) {
        return (size_t)(-1);
    }
    if (pageSeqInPartition < this->getMetaData()->getPartition(partitionId)->getNumPages()) {
        seekPageDirect(handle, pageSeqInPartition);
        ret = read(handle, pageInCache, length);
    } else {
        return (size_t)(-1);
    }
    return ret;
}