PartitionedFile::~PartitionedFile() {
    if (this->cleared == false) {
        pthread_mutex_lock(&this->fileMutex);
        this->closeAll();
        pthread_mutex_unlock(&this->fileMutex);
    }
    pthread_mutex_destroy(&this->fileMutex);
}