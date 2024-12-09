size_t DeviceIntf::stopCounters() {
    if (mVerbose) {
      std::cout << __func__ << ", " << std::this_thread::get_id() << ", "
                << ", Stop and reset device counters..." << std::endl;
    }

    if (!mIsDeviceProfiling)
   	  return 0;

    size_t size = 0;

    // Axi Interface Mons
    for(auto mon : mAimList) {
        size += mon->stopCounter();
    }


#if 0
    // These aren't enabled in IP
    // Accelerator Mons
    for(auto mon : mAmList) {
        size += mon->stopCounter();
    }

    // Axi Stream Mons
    for(auto mon : mAsmList) {
        size += mon->stopCounter();
    }
#endif
    return size;
  }