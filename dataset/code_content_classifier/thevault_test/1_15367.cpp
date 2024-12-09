PDBPagePtr PartitionPageIterator::next() {
    PDBPagePtr pageToReturn;
    if (this->numIteratedPages >= this->numPages) {
        return nullptr;
    } else {
        if (this->type == FileType::SequenceFileType) {
            pageToReturn = cache->getPage(this->sequenceFile, this->numIteratedPages);
            this->numIteratedPages++;
        } else {
            PageID curPageId =
                this->partitionedFile->loadPageId(this->partitionId, this->numIteratedPages);
            std::cout << this->partitionId << ": PartitionedPageIterator: curTypeId=" << this->partitionedFile->getTypeId()
                     << ",curSetId=" << this->partitionedFile->getSetId()
                     << ",curPageId=" << curPageId << "\n";
// page is pinned (ref count ++)
#ifdef USE_LOCALITY_SET
            pageToReturn = cache->getPage(this->partitionedFile,
                                          this->partitionId,
                                          this->numIteratedPages,
                                          curPageId,
                                          false,
                                          set);
#else
            pageToReturn = cache->getPage(this->partitionedFile,
                                          this->partitionId,
                                          this->numIteratedPages,
                                          curPageId,
                                          false,
                                          nullptr);
#endif
            PDB_COUT << "PartitionedPageIterator: got page" << std::endl;
            this->numIteratedPages++;
        }
    }
    return pageToReturn;
}