UAbstractClient::error_type
  UAbstractClient::pack(const char* command, ...)
  {
    if (rc)
      return -1;
    va_list arg;
    va_start(arg, command);
    rc = vpack(command, arg);
    va_end(arg);
    return rc;
  }