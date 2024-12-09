int PartitionedFile::writeData(FILE* file, void* data, size_t length) {

    if ((file == nullptr) || (data == nullptr)) {
        cout << "PartitionedFile: Error: writeData with nullptr.\n";
        return -1;
    }
    size_t retSize = fwrite(data, sizeof(char), length, file);
    fflush(file);
    if (retSize != length) {
        return -1;
    } else {
        return 0;
    }
}