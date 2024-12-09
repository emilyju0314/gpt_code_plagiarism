int PartitionedFile::seekNumFlushedPagesInPartitionMeta(FilePartitionID partitionId) {
    if (this->metaFile == nullptr) {
        return -1;
    }
    unsigned int i;
    unsigned int metaSize = sizeof(FileType) + sizeof(unsigned short) + sizeof(size_t) +
        sizeof(unsigned int) + sizeof(unsigned int);
    for (i = 0; i < partitionId; i++) {
        metaSize += sizeof(FilePartitionID) + sizeof(unsigned int) + sizeof(size_t) +
            this->dataPartitionPaths.at(i).length() + 1;
    }
    metaSize += sizeof(FilePartitionID);
    return fseek(this->metaFile, sizeof(size_t) + metaSize, SEEK_SET);
}