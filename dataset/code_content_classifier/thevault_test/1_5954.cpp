static
RTLD_HANDLE
xdlopen(const std::string& program,
        const std::string& msg,
        std::string path,
        sysexit status = EX_FAIL,
        int flags = RTLD_LAZY | RTLD_GLOBAL)
{
  path += libext;
  URBI_ROOT_DEBUG(program, "loading library: " << path << " (" << msg << ")");
  if (RTLD_HANDLE res = dlopen(path.c_str(), flags))
    return res;
  else
    URBI_ROOT_FATAL(program, status,
                    "cannot open library: " << path << ": " << dlerror());
}