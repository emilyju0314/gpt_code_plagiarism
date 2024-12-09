unsigned int PartitionedFile::getAndSetNumFlushedPages() {
    if (this->metaFile == nullptr) {
        return -1;
    }
    if (this->seekNumFlushedPagesInMeta() == 0) {
        this->logger->writeLn("PartitionedFile: get numFlushedPages from meta partition:");
        unsigned int numFlushedPages;
        size_t size =
            fread((unsigned int*)(&numFlushedPages), sizeof(unsigned int), 1, this->metaFile);
        if (size == 0) {
            std::cout << "PartitionedFile: Read failed" << std::endl;
            return 0;
        }
        this->getMetaData()->setNumFlushedPages(numFlushedPages);
        this->logger->writeInt(this->getMetaData()->getNumFlushedPages());
        return this->getMetaData()->getNumFlushedPages();
    } else {
        return 0;
    }
}