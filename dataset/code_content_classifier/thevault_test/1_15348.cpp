int PartitionedFile::writeDataDirect(int handle, void* data, size_t length) {
    if ((handle < 0) || (data == nullptr)) {
        cout << "PartitionedFile: Error: invalid handle or data is nullptr.\n";
        return -1;
    }
    size_t retSize = write(handle, data, length);
    if (retSize != length) {
        cout << "written bytes:" << retSize << "\n";
        return -1;
    } else {
        return 0;
    }
}