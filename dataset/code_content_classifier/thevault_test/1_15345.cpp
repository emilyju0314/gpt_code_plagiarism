size_t PartitionedFile::getPageSize() {
    if (pageSize == 0) {
        pageSize = getPageSizeInMeta();
    }
    return pageSize;
}