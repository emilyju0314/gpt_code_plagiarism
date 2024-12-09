bool PrepareElevate(DWORD &sid, bela::error_code &ec) {
  if (!IsUserAdministratorsGroup()) {
    ec = bela::make_error_code(1, L"current process not runing in administrator");
    return false;
  }
  auto hToken = INVALID_HANDLE_VALUE;
  constexpr DWORD flags = TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY;
  if (OpenProcessToken(GetCurrentProcess(), flags, &hToken) != TRUE) {
    ec = bela::make_system_error_code(L"PrepareElevate<OpenProcessToken> ");
    return false;
  }
  auto closer = bela::finally([&] { CloseHandle(hToken); });
  DWORD Length = 0;
  if (GetTokenInformation(hToken, TokenSessionId, &sid, sizeof(DWORD), &Length) != TRUE) {
    ec = bela::make_system_error_code(L"PrepareElevate<GetTokenInformation> ");
    return false;
  }
  TOKEN_PRIVILEGES tp;
  LUID luid;

  if (::LookupPrivilegeValueW(nullptr, SE_DEBUG_NAME, &luid) != TRUE) {

    ec = bela::make_system_error_code(L"PrepareElevate<LookupPrivilegeValueW> ");
    return false;
  }

  tp.PrivilegeCount = 1;
  tp.Privileges[0].Luid = luid;
  tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
  // Enable the privilege or disable all privileges.

  if (::AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), nullptr, nullptr) != TRUE) {
    ec = bela::make_system_error_code(L"PrepareElevate<AdjustTokenPrivileges> ");
    return false;
  }
  if (::GetLastError() == ERROR_NOT_ALL_ASSIGNED) {
    ec = bela::make_system_error_code(L"PrepareElevate<AdjustTokenPrivileges> ");
    return false;
  }
  return true;
}