void PartitionedFile::clear() {

    pthread_mutex_lock(&this->fileMutex);
    if (this->cleared == true) {

        pthread_mutex_unlock(&this->fileMutex);
        return;
    }
    this->closeAll();
    remove(this->metaPartitionPath.c_str());
    logger->info("PartitionedFile: Deleting file:" + this->metaPartitionPath);
    int i;
    int numPartitions = this->dataPartitionPaths.size();
    for (i = 0; i < numPartitions; i++) {
        remove(this->dataPartitionPaths.at(i).c_str());
        logger->info("PartitionedFile: Deleting file:" + this->dataPartitionPaths.at(i));
    }
    this->cleared = true;
    pthread_mutex_unlock(&this->fileMutex);
}