Status installService(const char* const binPath) {
  SC_HANDLE schSCManager = OpenSCManager(
      nullptr, nullptr, SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE);

  if (schSCManager == nullptr) {
    return Status(1);
  }

  SC_HANDLE schService =
      OpenService(schSCManager, kServiceName.c_str(), SERVICE_ALL_ACCESS);

  if (schService != nullptr) {
    CloseServiceHandle(schSCManager);
    return Status(1);
  }

  schService = CreateService(schSCManager,
                             kServiceName.c_str(),
                             kServiceName.c_str(),
                             SERVICE_ALL_ACCESS,
                             SERVICE_WIN32_OWN_PROCESS,
                             SERVICE_AUTO_START,
                             SERVICE_ERROR_NORMAL,
                             binPath,
                             nullptr,
                             nullptr,
                             nullptr,
                             nullptr, // User Account. nullptr => LOCAL SYSTEM
                             nullptr);

  CloseServiceHandle(schSCManager);
  CloseServiceHandle(schService);
  return Status(schService ? 0 : 1);
}