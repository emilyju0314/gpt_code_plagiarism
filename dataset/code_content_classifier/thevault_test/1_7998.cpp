static uint16_t
bdf2index(const std::string& bdfstr, bool _inUserDomain)
{
  //gather available devices for user to pick from
  std::stringstream available_devs;
  available_devs << "\n Available devices:\n";
  boost::property_tree::ptree available_devices = get_available_devices(_inUserDomain);
  for(auto& kd : available_devices) {
    boost::property_tree::ptree& dev = kd.second;
    available_devs << boost::format("  [%s] : %s\n") % dev.get<std::string>("bdf") % dev.get<std::string>("vbnv");
  }

  if(!std::regex_match(bdfstr,std::regex("[A-Za-z0-9:.]+")))
    throw std::runtime_error("Invalid BDF format. Please specify valid BDF" + available_devs.str());

  std::vector<std::string> tokens; 
  boost::split(tokens, bdfstr, boost::is_any_of(":")); 
  int radix = 16;
  uint16_t bus = 0; 
  uint16_t dev = 0; 
  uint16_t func = std::numeric_limits<uint16_t>::max();

  // check if we have 2-3 tokens: domain, bus, device.function
  // domain is optional
  if(tokens.size() <= 1 || tokens.size() > 3)
    throw std::runtime_error(boost::str(boost::format("Invalid BDF '%s'. Please spcify the BDF using 'DDDD:BB:DD.F' format") % bdfstr) + available_devs.str());

  std::reverse(std::begin(tokens), std::end(tokens));

  //check if func was specified. func is optional
  auto pos_of_func = tokens[0].find('.');
  if(pos_of_func != std::string::npos) {
    dev = static_cast<uint16_t>(std::stoi(std::string(tokens[0].substr(0, pos_of_func)), nullptr, radix));
    func = static_cast<uint16_t>(std::stoi(std::string(tokens[0].substr(pos_of_func+1)), nullptr, radix));
  }
  else{
    dev = static_cast<uint16_t>(std::stoi(std::string(tokens[0]), nullptr, radix));
  }
  bus = static_cast<uint16_t>(std::stoi(std::string(tokens[1]), nullptr, radix));

  uint64_t devices = _inUserDomain ? xrt_core::get_total_devices(true).first : xrt_core::get_total_devices(false).first;
  for (uint16_t i = 0; i < devices; i++) {
    auto device = _inUserDomain ? xrt_core::get_userpf_device(i) : xrt_core::get_mgmtpf_device(i);
    auto bdf = xrt_core::device_query<xrt_core::query::pcie_bdf>(device);

    //if the user specifies func, compare
    //otherwise safely ignore
    auto cmp_func = [bdf](uint16_t func) 
    {
      if (func != std::numeric_limits<uint16_t>::max())
        return func == std::get<2>(bdf);
      return true;
    };

    if (bus == std::get<0>(bdf) && dev == std::get<1>(bdf) && cmp_func(func))
      return i;
  }

  throw std::runtime_error(boost::str(boost::format("Specified device BDF '%s' not found") % bdfstr) + available_devs.str());
}