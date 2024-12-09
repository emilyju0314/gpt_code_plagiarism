void BufferManager::removeFile(string filename) {
    for (auto &block : blockBuffer) {
        if (block.filename == filename) {
            block.reset();
        }
    }
    if (remove(filename.c_str())) {
        cerr << "Fail to remove file: " << filename << endl;
    }
}