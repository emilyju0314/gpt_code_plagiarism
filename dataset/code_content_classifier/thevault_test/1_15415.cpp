PDBPagePtr UserSet::getPage(FilePartitionID partitionId,
                            unsigned int pageSeqInPartition,
                            PageID pageId) {

    /**
     * check whether the page is already in cache using cache key, if so return it.
     * otherwise, check whether the page is flushed to disk file, if so, load it to cache, and
     * return it.
     */
    return this->pageCache->getPage(
        this->file, partitionId, pageSeqInPartition, pageId, false, this);
}