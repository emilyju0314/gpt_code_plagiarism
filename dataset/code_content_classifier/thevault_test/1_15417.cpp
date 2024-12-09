vector<PageIteratorPtr>* UserSet::getIteratorsExtended(SetPtr sharedSet) {

     vector<PageIteratorPtr>* retVec = this->getIterators();
     //now we should retrieve the iterator for shared pages of this set
     PartitionedFilePtr sharedFile = sharedSet->getFile();
     int numPartitions = sharedFile->getNumPartitions();
     std::cout << "SharedFile has " << numPartitions << " partitions" << std::endl;
     PageIteratorPtr iterator = nullptr;
     for (int i = 0; i < numPartitions; i++) {
        iterator = make_shared<pdb::PartitionTensorBlockSharedPageIterator>(this->pageCache, file, sharedFile, i, dynamic_pointer_cast<pdb::SharedFFMatrixBlockSet>(sharedSet), dbId, typeId, setId);
        retVec->push_back(iterator);
     }

     return retVec;

    
}