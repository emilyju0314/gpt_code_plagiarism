static void 
auto_flash(xrt_core::device_collection& deviceCollection, bool force) 
{
  //report status of all the devices
  boost::property_tree::ptree _pt;
  report_status(deviceCollection, _pt);

  // Collect all indexes of boards need updating
  std::vector<std::pair<unsigned int , DSAInfo>> boardsToUpdate;
  for (const auto & device : deviceCollection) {
    DSAInfo dsa(_pt.get_child(std::to_string(device->get_device_id()) + ".platform.available_shells").front().second.get<std::string>("file"));
    //if the shell is not up-to-date and dsa has a flash image, queue the board for update
    bool same_shell = _pt.get<bool>(std::to_string(device->get_device_id()) + ".platform.status.shell");
    bool same_sc = _pt.get<bool>(std::to_string(device->get_device_id()) + ".platform.status.sc");

    // Always update Arista devices
    auto vendor = xrt_core::device_query<xrt_core::query::pcie_vendor>(device);
    if (vendor == ARISTA_ID)
        same_shell = false;

    if (!same_shell || !same_sc) {
      if(!dsa.hasFlashImage)
        throw xrt_core::error("Flash image is not available");
      boardsToUpdate.push_back(std::make_pair(device->get_device_id(), dsa));
    }
  }

  // Continue to flash whatever we have collected in boardsToUpdate.
  uint16_t success = 0;
  bool needreboot = false;
  std::stringstream report_status;
  if (!boardsToUpdate.empty()) {

    // Prompt user about what boards will be updated and ask for permission.
    if(!force && !XBU::can_proceed())
      return;

    // Perform DSA and BMC updating
    for (auto& p : boardsToUpdate) {
      bool reboot;
      std::cout << std::endl;
      try {
        updateShellAndSC(p.first, p.second, reboot);
        report_status << boost::format("  [%s] : Successfully flashed\n") % getBDF(p.first);
        success++;
      } catch (const xrt_core::error& e) {
        std::cerr << boost::format("ERROR: %s\n") % e.what();
      }
      needreboot |= reboot;
    }
  }
  std::cout << "----------------------------------------------------\n";
  std::cout << "Report\n";
  //report status of cards
  std::cout << report_status.str();
  if (boardsToUpdate.size() == 0) {
    std::cout << "\nCard(s) up-to-date and do not need to be flashed." << std::endl;
    return;
  }

  if (success != 0) {
    std::cout << "\n" << success << " Card(s) flashed successfully." << std::endl; 
  } else {
    std::cout << "\nNo cards were flashed." << std::endl; 
  }

  if (needreboot) {
    std::cout << "****************************************************\n";
    std::cout << "Cold reboot machine to load the new image on card(s).\n";
    std::cout << "****************************************************\n";
  }

  if (success != boardsToUpdate.size()) {
    std::cout << "WARNING:" << boardsToUpdate.size()-success << " Card(s) not flashed. " << std::endl;
  }
}