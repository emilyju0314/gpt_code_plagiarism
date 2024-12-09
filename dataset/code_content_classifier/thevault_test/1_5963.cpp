int Metadata::resetAllChunks(const char* metaFile, int force) {
    LoadMetadata(metaFile);
    if (force == 0 && in_use_ != 0) return -1;
    in_use_ = 0;
    for (int i = 0 ; i < chunks_ ; i++) {
        chunkInfo_[i].status = CH_PENDING;
    }
    SaveMetadata(metaFile);

    return 0;
}