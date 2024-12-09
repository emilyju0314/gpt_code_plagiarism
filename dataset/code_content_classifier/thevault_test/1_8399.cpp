void MemWrapper::ramInit(){
    ramData.resize(GL::vecLen * 4 * (int)sizeof(float)); 

    std::vector<float> vec0;
    std::vector<float> vec1;
    std::vector<float> vec2;
    std::vector<float> result;
    vec0.resize(GL::vecLen);
    vec1.resize(GL::vecLen);
    vec2.resize(GL::vecLen);
    result.resize(GL::vecLen);

    for(int i = 0; i < GL::vecLen; i++){
        vec0[i] = (rand()%100)/10.0;
        vec1[i] = (rand()%100)/10.0;
        vec2[i] = 0;
        result[i] = vec0[i] + vec1[i];
    }

    auto alignMyself = [](long addr)->long{
        int bw = 8;
        long mask = 0xFF;
        long alignedAddr = addr;
        if((addr & mask) != 0){
            alignedAddr = ((addr >> bw) + 1) << bw; 
        }
        return alignedAddr;
    };

    // Init memory
    long addr0 = GL::vecMemAddr0 = 0;
    long addr1 = addr0 + (long)sizeof(float) * GL::vecLen;
    GL::vecMemAddr1 = addr1 = alignMyself(addr1);
    long addr2 = addr1 + (long)sizeof(float) * GL::vecLen;
    GL::vecMemAddr2 = addr2 = alignMyself(addr2);
    long resultAddr = addr2 + (long)sizeof(float) * GL::vecLen;
    GL::resultMemAddr = resultAddr = alignMyself(resultAddr);

    // fill memory with the data
    auto fillMem = [this](const std::vector<float> &vec, long &addr){
        for(auto val : vec){
            updateSingleDataToRam<float>(addr, val);
            addr += (long)sizeof(float);
        }
    };

    fillMem(vec0, addr0);
    fillMem(vec1, addr1);
    fillMem(vec2, addr2);
    fillMem(result, resultAddr);
}