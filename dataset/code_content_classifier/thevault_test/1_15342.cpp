PageID PartitionedFile::loadPageIdFromCurPos(FilePartitionID partitionId,
                                             unsigned int pageSeqInPartition,
                                             char* pageInCache,
                                             size_t length) {
    FILE* curFile = this->dataFiles.at(partitionId);
    if (curFile == nullptr) {
        return 0;
    }
    if (pageSeqInPartition < this->getMetaData()->getPartition(partitionId)->getNumPages()) {
        PageID pageId;
        size_t size = fread(&pageId, sizeof(char), sizeof(PageID), curFile);
        if (size == 0) {
            std::cout << "PartitionedFile: Read failed" << std::endl;
            return (PageID)(-1);
        }
        return pageId;
    } else {
        return (PageID)(-1);
    }
}