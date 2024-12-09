void Metadata::resetDownloadingChunks(const char* metaFile, int force) {
    LoadMetadata(metaFile);
    if (in_use_ != 0 && force == 0) {
        printf("mhclient is still running or was aborted.\n");
        printf("If the client is not running try ");
        printf("--recover/-r --force/-f\n");
        exit(1);
    }
    in_use_ = 0;
    for (int i = 0 ; i < chunks_ ; i++) {
        if (chunkInfo_[i].status == CH_DOWNLOAD ||
                chunkInfo_[i].status == CH_ERROR) {
            chunkInfo_[i].status = CH_PENDING;
        }
    }
    SaveMetadata(metaFile);
}