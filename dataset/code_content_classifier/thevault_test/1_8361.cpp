CanDeviceOptions(
        const uint32_t nodeId,
        const std::string& name,
        const double timeout,
        const double looprate):
        CanDeviceOptions(nodeId, name, static_cast<unsigned int>(timeout*looprate))
    {
    }