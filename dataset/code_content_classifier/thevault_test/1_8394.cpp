MemWrapper::MemWrapper(sc_module_name _name,
        double _memClkCycle,
        double _peClkCycle,
        int argc, 
        char* argv[]) 
    : sc_module(_name), configs(argv[1]){

    loadConfig(argc, argv);
    memClkCycle = _memClkCycle; 
    peClkCycle = _peClkCycle; 
    GL::burstLen = calBurstLen();
    burstReqQueues.resize(GL::portNum);
    burstRespQueues.resize(GL::portNum);
    ramInit();

    SC_THREAD(runMemSim);
    SC_THREAD(getBurstReq);
    SC_THREAD(sendBurstResp);
    SC_THREAD(statusMonitor);

}