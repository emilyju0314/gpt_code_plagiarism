void
  prepend_path_to_os_libpath(cet::search_path const& sp)
  {
    std::string new_os_libpath;
    std::set<std::string> paths;
    auto const np_sz = sp.size();
    for (auto i = 0ull; i != np_sz; ++i) {
      if (!new_os_libpath.empty()) {
        new_os_libpath.append(":");
      }
      new_os_libpath.append(sp[i]);
      paths.insert(sp[i]);
    }
    cet::search_path oslp{cet::os_libpath(), std::nothrow};
    auto const oslp_sz = oslp.size();
    for (auto i = 0ull; i != oslp_sz; ++i) {
      if (paths.find(oslp[i]) == paths.end()) {
        if (!new_os_libpath.empty()) {
          new_os_libpath.append(":");
        }
        new_os_libpath.append(oslp[i]);
        paths.insert(oslp[i]);
      }
    }
    setenv(cet::os_libpath(), new_os_libpath.c_str(), 1);
  }