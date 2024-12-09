void OpenCLDeviceOffloadPlugin::flushDevice(void* d)
  {
    if (!active) return ;
    if (getFlowMode() == SW_EMU) return ;

    xrt_xocl::device* device = static_cast<xrt_xocl::device*>(d) ;

    std::string path = device->getDebugIPlayoutPath().get() ;

    uint64_t deviceId = db->addDevice(path) ;
    
    if (offloaders.find(deviceId) != offloaders.end())
    {
      std::get<0>(offloaders[deviceId])->read_trace() ;
    }
  }