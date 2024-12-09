int PartitionedFile::seekNumFlushedPagesInMeta() {
    if (this->metaFile == nullptr) {
        return -1;
    }
    return fseek(this->metaFile,
                 sizeof(size_t) + sizeof(FileType) + sizeof(unsigned short) + sizeof(size_t),
                 SEEK_SET);
}