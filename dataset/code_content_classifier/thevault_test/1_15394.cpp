int PageCircularBuffer::addPageToTail(PDBPagePtr page) {
    pthread_mutex_lock(&(this->addPageMutex));
    int i = 0;
    while (this->isFull()) {
        i++;
        if (i % 10000000 == 0) {
            this->logger->info(std::to_string(i) +
                               std::string(":PageCircularBuffer: array is full."));
            std::cout << i << ":PageCircularBuffer: array is full." << std::endl;
        }
        pthread_cond_signal(&(this->cond));
        sched_yield();  // TODO: consider to use another conditional variable
    }

    this->logger->writeLn("PageCircularBuffer:got a place.");
    std::cout << "PageCircularBuffer:got a place." << std::endl;
    this->pageArrayTail = (this->pageArrayTail + 1) % this->maxArraySize;
    this->pageArray[this->pageArrayTail] = page;
    pthread_mutex_unlock(&(this->addPageMutex));
    pthread_mutex_lock(&(this->mutex));
    if (this->getSize() <= 2) {  // TODO <= numThreads? or not necessary
        pthread_cond_broadcast(&(this->cond));
    } else {
        pthread_cond_signal(&(this->cond));
    }
    pthread_mutex_unlock(&(this->mutex));
    return 0;
}