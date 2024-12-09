vector<PageIteratorPtr>* UserSet::getIterators() {

    this->cleanDirtyPageSet();
    this->lockDirtyPageSet();
    vector<PageIteratorPtr>* retVec = new vector<PageIteratorPtr>();
    PageIteratorPtr iterator = nullptr;
    if (dirtyPagesInPageCache->size() > 0) {
        std::cout << "dirtyPages size=" << dirtyPagesInPageCache->size() << std::endl;
        iterator = make_shared<SetCachePageIterator>(this->pageCache, this);
        if (iterator != nullptr) {
            retVec->push_back(iterator);
        }
    }
    if (this->file->getFileType() == FileType::SequenceFileType) {
        SequenceFilePtr seqFile = dynamic_pointer_cast<SequenceFile>(this->file);
        iterator =
            make_shared<PartitionPageIterator>(this->pageCache, file, (FilePartitionID)0, this);
        retVec->push_back(iterator);
    } else {
        PartitionedFilePtr partitionedFile = dynamic_pointer_cast<PartitionedFile>(this->file);
        int numPartitions = partitionedFile->getNumPartitions();
        std::cout<<"We have " << numPartitions << " partitions" << std::endl;
        int i = 0;
        for (i = 0; i < numPartitions; i++) {
            if (partitionedFile->getMetaData()->getPartition(i)->getNumPages() > 0) {
                std::cout << "numpages in partition:" << i << " ="
                         << partitionedFile->getMetaData()->getPartition(i)->getNumPages()
                         << std::endl;
                iterator = make_shared<PartitionPageIterator>(
                    this->pageCache, file, (FilePartitionID)i, this);
                retVec->push_back(iterator);
            }
        }
    }
    this->unlockDirtyPageSet();
    return retVec;
}