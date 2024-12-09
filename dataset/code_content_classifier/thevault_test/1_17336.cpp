std::string runKernelDumper(KernelDumper *kernelDumper, int numClmemArgs) {
    // assumes all args unique
    vector<int> clmemIndexByClmemArgIndex;
    for(int i = 0; i < numClmemArgs; i++) {
        clmemIndexByClmemArgIndex.push_back(i);
    }
    std::string cl = kernelDumper->toCl(numClmemArgs, clmemIndexByClmemArgIndex);
    return cl;
}