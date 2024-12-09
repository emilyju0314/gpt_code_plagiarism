bool PartitionPageIterator::hasNext() {
    if (this->numIteratedPages < this->numPages) {
        return true;
    } else {
        return false;
    }
}