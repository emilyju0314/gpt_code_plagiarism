bool PartitionedFile::closeDirect() {
    int i;
    int numPartitions = this->dataPartitionPaths.size();
    fclose(this->metaFile);
    for (i = 0; i < numPartitions; i++) {
        close(this->dataHandles.at(i));
    }
    return true;
}