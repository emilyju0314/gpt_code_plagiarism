void
cb_action_ndrange(xocl::event* event,cl_int status,const std::string& cu_name, cl_kernel kernel,
                  std::string kname, std::string xname, size_t workGroupSize, const size_t* globalWorkDim,
                  const size_t* localWorkDim, unsigned int programId)
{
    if (!isProfilingOn())
      return;

    // Create string to specify event and its dependencies
    std::string eventStr;
    std::string dependStr;
    if (status == CL_RUNNING || status == CL_COMPLETE) {
      eventStr = get_event_string(event);
      dependStr = get_event_dependencies_string(event);
      XOCL_DEBUGF("KERNEL status: %d, event: %s, depend: %s\n", status, eventStr.c_str(), dependStr.c_str());
    }

    auto queue = event->get_command_queue();
    auto device = queue->get_device();
    auto commandState = event_status_to_profile_state(status);
    auto contextId =  event->get_context()->get_uid();
    auto commandQueueId = queue->get_uid();
    auto deviceName = device->get_name();
    auto deviceId = device->get_uid();
    double timestampMsec = 0.0;
    timestampMsec = (status == CL_COMPLETE) ? (event->time_end()) / 1e6 : timestampMsec;
    timestampMsec = (status == CL_RUNNING) ? (event->time_start()) / 1e6 : timestampMsec;
    // Create and insert trace string in xdp plugin
    std::string uniqueDeviceName = deviceName + "-" + std::to_string(deviceId);
    std::string localSize = std::to_string(localWorkDim[0]) + ":" +
                            std::to_string(localWorkDim[1]) + ":" +
                            std::to_string(localWorkDim[2]);
    std::string CuInfo = kname + "|" + localSize;
    std::string uniqueName = "KERNEL|" + uniqueDeviceName + "|" + xname + "|" + CuInfo + "|";
    std::string traceString = uniqueName + std::to_string(workGroupSize);
    OCLProfiler::Instance()->getPlugin()->setTraceStringForComputeUnit(kname, traceString);
    // Log Buffers associated with this kernel
    log_buffer_guidance(event, kernel);
    // Finally log the execution
    OCLProfiler::Instance()->getProfileManager()->logKernelExecution
      ( reinterpret_cast<uint64_t>(kernel)
       ,programId
       ,reinterpret_cast<uint64_t>(event)
       ,commandState
       ,kname
       ,xname
       ,contextId
       ,commandQueueId
       ,deviceName
       ,deviceId
       ,globalWorkDim
       ,workGroupSize
       ,localWorkDim
       ,cu_name
       ,eventStr
       ,dependStr
       ,timestampMsec);
}