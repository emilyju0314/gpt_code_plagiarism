bool Metadata::HasMetadataFile(const char *fileName, bool loadMetadata) {
    const char *fileAbsolute;
    char fileMetadata[1024];
    char fileFull[2048];

    memset(fileMetadata , 0 , sizeof(fileMetadata));
    memset(fileFull     , 0 , sizeof(fileFull));

    fileAbsolute = AbsoluteFile(fileName);

    StrCat(fileFull , fileName);

    StrCat(fileMetadata , fileAbsolute);
    StrCat(fileMetadata , ".mdata");

    DEBUG("HasMetadataFile : check for <%s>\n", fileMetadata);

    if (access(fileMetadata, F_OK) != -1) {
        // File exists
        DEBUG("HasMetadataFile file <%s> exists\n", fileMetadata);
        if (loadMetadata) {
            CopyString(fileMetadata_, fileMetadata);
            LoadMetadata();
        }
        return true;
    } else {
        // File does not exist
        DEBUG("HasMetadataFile file <%s> does not exist\n", fileMetadata);
        return false;
    }
}