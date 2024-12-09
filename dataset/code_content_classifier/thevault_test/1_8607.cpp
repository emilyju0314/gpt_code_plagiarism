uint8_t* readFlatBuffers(const char * filename) {
    long fileLen = getFileSize(filename);
    if (fileLen < 0) {
        nd4j_printf("File [%s] wasn't found. Please check path and permissions\n", filename);
        throw std::runtime_error("File not found");
    }

    nd4j_debug("File length: %i\n", fileLen);

    uint8_t * data = new uint8_t[fileLen];

    FILE *in = fopen(filename, "rb");
    int cnt = 0;
    int b = 0;
    while (cnt < fileLen) {
        b = fread(data + cnt, 1, 1, in);

        cnt += b;
    }
    fclose(in);

    return data;
}