std::vector<VTFEvent*> VPDynamicDatabase::filterEvents(std::function<bool(VTFEvent*)> filter)
  {
    std::lock_guard<std::mutex> lock(dbLock) ;
    std::vector<VTFEvent*> collected ;

    // For now, go through both host events and device events.
    for (auto e : hostEvents)
    {
      if (filter(e)) collected.push_back(e) ;
    }

    for (auto dev : deviceEvents)
    {
      for (auto multiMapEntry : dev.second)
      {
	if (filter(multiMapEntry.second)) collected.push_back(multiMapEntry.second) ;
      }
    }

    return collected ;
  }