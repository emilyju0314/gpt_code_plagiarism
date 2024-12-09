void MemWrapper::getBurstReq(){
    while(true){
        auto reqProcess = [this](long burstIdx){
            if(burstIdx != -1){
                BurstOp* ptr = GL::bursts[burstIdx];
                burstReqQueues[ptr->portIdx].push_back(burstIdx);
                totalReqNum[burstIdx] = ptr->getReqNum();
                processedReqNum[burstIdx] = 0;
                ptr->convertToReq(reqQueue);
            }
        };
        
        reqProcess(req0.read());
        reqProcess(req1.read());
        reqProcess(req2.read());

        wait(peClkCycle, SC_NS);
    }
}