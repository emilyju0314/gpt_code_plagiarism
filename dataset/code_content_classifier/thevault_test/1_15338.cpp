int PartitionedFile::updateMeta() {
    if (this->seekNumFlushedPagesInMeta() < 0) {
        return -1;
    }
    unsigned int numFlushedPages = this->getMetaData()->getNumFlushedPages();
    if (this->writeData(this->metaFile, &numFlushedPages, sizeof(unsigned int)) < 0) {
        return -1;
    }
    unsigned int numPartitions = this->dataPartitionPaths.size();
    unsigned int i;
    for (i = 0; i < numPartitions; i++) {
        this->seekNumFlushedPagesInPartitionMeta(i);
        numFlushedPages = this->getMetaData()->getPartition(i)->getNumPages();
        if (this->writeData(this->metaFile, &(numFlushedPages), sizeof(unsigned int)) < 0) {
            return -1;
        }
    }
    fflush(this->metaFile);
    return 0;
}