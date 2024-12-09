int PartitionedFile::seekPage(FILE* partition, unsigned int pageSeqInPartition) {
    if (partition == nullptr) {
        return -1;
    }
    return fseek(partition, (pageSeqInPartition) * (this->metaData->getPageSize()), SEEK_SET);
}