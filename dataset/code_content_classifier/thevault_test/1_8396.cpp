void MemWrapper::sendBurstResp(){
    while(true){
        auto respProcess = [this](int pidx)->long{
            if(burstReqQueues[pidx].empty()){
                return -1;
            }

            int idx = burstReqQueues[pidx].front();
            if(std::find(burstRespQueues[pidx].begin(),
               burstRespQueues[pidx].end(), 
               idx) == burstRespQueues[pidx].end())
            {
                return -1;
            }
            else{
                BurstOp* ptr = GL::bursts[idx];
                long respReadyTime = ptr->departMemTime; 
                long currentTimeStamp = (long)(sc_time_stamp()/sc_time(1, SC_NS));
                if(respReadyTime <= currentTimeStamp){
                    if(ptr->type == ramulator::Request::Type::WRITE){
                        ptr->reqToRam(ramData);
                    }
                    else{
                        ptr->ramToReq(ramData);
                    }
                    burstReqQueues[pidx].remove(idx);
                    burstRespQueues[pidx].remove(idx);
                    return idx;
                }
            }
            return -1;
        };

        resp0.write(respProcess(0));
        resp1.write(respProcess(1));
        resp2.write(respProcess(2));

        wait(peClkCycle, SC_NS);
    }
}