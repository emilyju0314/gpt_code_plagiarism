CanDeviceOptions(
        const uint32_t nodeId,
        const std::string& name,
        const unsigned int maxDeviceTimeoutCounter = 20):
        nodeId_(nodeId),
        name_(name),
        maxDeviceTimeoutCounter_(maxDeviceTimeoutCounter),
        printConfigInfo_(true)
    {
    }