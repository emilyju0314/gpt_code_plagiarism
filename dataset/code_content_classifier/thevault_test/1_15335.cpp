bool PartitionedFile::closeAll() {
    if (usingDirect == true) {
        return closeDirect();
    }
    int i;
    int numPartitions = this->dataPartitionPaths.size();
    fclose(this->metaFile);
    this->metaFile = nullptr;
    for (i = 0; i < numPartitions; i++) {
        fclose(this->dataFiles.at(i));
        this->dataFiles.at(i) = nullptr;
    }
    return true;
}