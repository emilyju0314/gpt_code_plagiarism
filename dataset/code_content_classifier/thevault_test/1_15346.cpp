size_t PartitionedFile::getPageSizeInMeta() {
    if (this->metaFile == nullptr) {
        return (size_t)(-1);
    }
    if (this->seekPageSizeInMeta() == 0) {
        size_t pageSize;
        this->logger->writeLn("PartitionedFile: get page size from meta partition:");
        size_t sizeRead = fread((size_t*)(&(pageSize)), sizeof(size_t), 1, this->metaFile);
        if (sizeRead == 0) {
            std::cout << "PartitionedFile: Read failed" << std::endl;
            return 0;
        }
        this->logger->writeInt(pageSize);
        return pageSize;
    } else {
        return 0;
    }
}