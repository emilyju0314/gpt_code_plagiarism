void DeviceOffloadPlugin::addOffloader(uint64_t deviceId,
					 DeviceIntf* devInterface)
  {
    if (!active) return ;

    // If offload via memory is requested, make sure the size requested
    //  fits inside the chosen memory resource.
    uint64_t trace_buffer_size = GetTS2MMBufSize() ;
    if (devInterface->hasTs2mm()) {
      Memory* memory = (db->getStaticInfo()).getMemory(deviceId, devInterface->getTS2MmMemIndex());
      if(nullptr == memory) {
        std::string msg = "Information about memory index " + std::to_string(devInterface->getTS2MmMemIndex()) 
                           + " not found in given xclbin. So, cannot check availability of memory resource for device trace offload.";
        xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", msg);
        return;
      } else {
        uint64_t memorySz = (memory->size) * 1024 ;
        if (memorySz > 0 && trace_buffer_size > memorySz) {
          trace_buffer_size = memorySz ;
          std::string msg = "Trace buffer size is too big for memory resource.  Using " + std::to_string(memorySz) + " instead." ;
          xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", msg) ;
        }
      }
    }

    TraceLoggerCreatingDeviceEvents* logger = 
      new TraceLoggerCreatingDeviceEvents(deviceId) ;

    DeviceTraceOffload* offloader = 
      new DeviceTraceOffload(devInterface, logger,
                         continuous_trace_interval_ms, // offload_sleep_ms,
                         trace_buffer_size,            // trbuf_size,
                         continuous_trace);            // start_thread

    bool init_successful = offloader->read_trace_init() ;
    if (!init_successful) {
      if (devInterface->hasTs2mm()) {
        xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", TS2MM_WARN_MSG_ALLOC_FAIL) ;
      }
      delete offloader ;
      delete logger ;
      return ;
    }
    offloaders[deviceId] = std::make_tuple(offloader, logger, devInterface) ;
  }