DataBuffer::DataBuffer(const void* hostBuffer, const DataType dataType, const size_t lenInBytes, memory::Workspace* workspace) {

        if (hostBuffer == nullptr)
            throw std::runtime_error("DataBuffer constructor: can't be initialized with nullptr host buffer !");
        if (lenInBytes == 0)
            throw std::runtime_error("DataBuffer constructor: can't be initialized with zero length !");

        _primaryBuffer  = nullptr;
        _specialBuffer  = nullptr;
        _lenInBytes     = lenInBytes;
        _dataType       = dataType;
        _workspace      = workspace;

        _deviceId = sd::AffinityManager::currentDeviceId();

        setCountersToZero();

        allocateBuffers();

        copyBufferFromHost(hostBuffer, lenInBytes);
    }