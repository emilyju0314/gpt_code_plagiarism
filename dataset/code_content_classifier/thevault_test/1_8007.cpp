static void 
update_shell(unsigned int index, const std::string& flashType,
  const std::string& primary, const std::string& secondary)
{
  if (!flashType.empty()) {
      xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", 
        "Overriding flash mode is not recommended.\nYou may damage your card with this option.");
  }

  Flasher flasher(index);
  if(!flasher.isValid())
    throw xrt_core::error(boost::str(boost::format("%d is an invalid index") % index));

  if (primary.empty())
    throw xrt_core::error("Shell not specified");

  auto pri = std::make_unique<firmwareImage>(primary.c_str(), MCS_FIRMWARE_PRIMARY);
  if (pri->fail())
    throw xrt_core::error(boost::str(boost::format("Failed to read %s") % primary));

  std::unique_ptr<firmwareImage> sec;
  if (!secondary.empty()) {
    sec = std::make_unique<firmwareImage>(secondary.c_str(), MCS_FIRMWARE_SECONDARY);
    if (sec->fail())
      throw xrt_core::error(boost::str(boost::format("Failed to read %s") % secondary));
  }

  if (flasher.upgradeFirmware(flashType, pri.get(), sec.get()) != 0)
    throw xrt_core::error("Failed to update shell");
  
  std::cout << boost::format("%-8s : %s \n") % "INFO" % "Shell is updated successfully.";
  std::cout << "****************************************************\n";
  std::cout << "Cold reboot machine to load the new image on card.\n";
  std::cout << "****************************************************\n";
}