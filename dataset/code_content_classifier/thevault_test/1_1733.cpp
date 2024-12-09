bool MutexSet::GetMutex(const std::string& name, bool init_value,
                        bool allow_multi_post, Mutex* mutex) {
  if (mutexes_.find(name) == mutexes_.end()) {
    Logger::Log(EVENT_ERROR, "unregistered mutex name: [%s].", name.c_str());
    return false;
  }

  // try to retrieve events.
  if (events_.find(name) != events_.end()) {
    mutex->Initialize(allow_multi_post, events_[name]);
    return true;
  }

  // Try to open or create it.
  HANDLE event = NULL;
  if (!server_) {
    event = OpenEventA(EVENT_ALL_ACCESS, false, name.c_str());
  } else {
    // Initialize security attribute.
    SECURITY_ATTRIBUTES sa;
    SECURITY_DESCRIPTOR sd;
    PACL pacl;
    if (!AccessController::BuildIPCSecurityDescriptor(&sa, &sd, &pacl)) {
      Logger::Log(EVENT_ERROR, "Failed to build acl for events set.");
      return false;
    }

    event = CreateEventA(&sa, false, init_value, name.c_str());

    LocalFree(pacl);
  }

  if (event == NULL) {
    Logger::Log(EVENT_ERROR, "Failed to open/create [%s] event. (%d)",
              name.c_str(), GetLastError());
    return false;
  }

  events_[name] = event;
  mutex->Initialize(allow_multi_post, event);
  return true;
}