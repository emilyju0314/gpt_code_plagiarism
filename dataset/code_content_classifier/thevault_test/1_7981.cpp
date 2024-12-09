void
load_xdp()
{
  struct xdp_once_loader
  {
    xdp_once_loader()
    {
      bfs::path xrt(emptyOrValue(getenv("XILINX_XRT")));

      if (xrt.empty()) {
#if defined (__aarch64__) || defined (__arm__)
        xrt = bfs::path("/usr");
#else
        throw std::runtime_error("Library oclxdp not found! XILINX_XRT not set");
#endif
      }
      bfs::path xrtlib(xrt / "lib");
      directoryOrError(xrtlib);
      auto libname = dllpath(xrt, "oclxdp");
      if (!isDLL(libname)) {
        throw std::runtime_error("Library " + libname.string() + " not found!");
      }
      auto handle = xrt_core::dlopen(libname.string().c_str(), RTLD_NOW | RTLD_GLOBAL);
      if (!handle)
        throw std::runtime_error("Failed to open XDP library '" + libname.string() + "'\n" + xrt_core::dlerror());

      typedef void (* xdpInitType)();

      const std::string s = "initXDPLib";
      auto initFunc = (xdpInitType)xrt_core::dlsym(handle, s.c_str());
      if (!initFunc)
        throw std::runtime_error("Failed to initialize XDP library, '" + s +"' symbol not found.\n" + xrt_core::dlerror());

      initFunc();
    }
  };

  // 'magic static' is thread safe per C++11
  static xdp_once_loader xdp_loaded;
}