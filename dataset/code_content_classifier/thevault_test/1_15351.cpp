int PartitionedFile::seekPageSizeInMeta() {
    if (this->metaFile == nullptr) {
        return -1;
    }
    return fseek(
        this->metaFile, sizeof(size_t) + sizeof(FileType) + sizeof(unsigned short), SEEK_SET);
}