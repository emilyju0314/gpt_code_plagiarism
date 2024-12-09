int PartitionedFile::seekPageDirect(int handle, unsigned int pageSeqInPartition) {
    if (handle < 0) {
        return -1;
    }
    return lseek(handle, (pageSeqInPartition) * (this->metaData->getPageSize()), SEEK_SET);
}