std::vector<DSAInfo> Flasher::getInstalledDSA()
{
    std::vector<DSAInfo> DSAs;

    // Obtain board info.
    DSAInfo onBoard = getOnBoardDSA();
    std::string err;

    if (onBoard.name.empty() && onBoard.uuids.empty())
    {
        std::cout << "Shell on FPGA is unknown" << std::endl;
    }

    auto vendor_id = xrt_core::device_query<xrt_core::query::pcie_vendor>(m_device);
    auto device_id = xrt_core::device_query<xrt_core::query::pcie_device>(m_device);

    // Obtain installed DSA info.
    // std::cout << "ON Board: " << onBoard.vendor << " " << onBoard.board << " " << vendor_id << " " << device_id << std::endl;
    auto installedDSAs = firmwareImage::getIntalledDSAs();
    for (const auto& dsa : installedDSAs)
    {
        // std::cout << "DSA " << dsa.name << ": " << dsa.vendor << " " << dsa.board << " " << dsa.vendor_id << " " << dsa.device_id << "TS: " << dsa.timestamp << std::endl;
        if (!dsa.hasFlashImage || dsa.timestamp == NULL_TIMESTAMP)
	       continue;

        if (!onBoard.vendor.empty() && !onBoard.board.empty() &&
            (onBoard.vendor == dsa.vendor) &&
            (onBoard.board == dsa.board))
        {
            DSAs.push_back(dsa);
        }
	else if (!dsa.name.empty() && (vendor_id == dsa.vendor_id) && (device_id == dsa.device_id))
        {
            DSAs.push_back(dsa);
        } else if (onBoard.name.empty())
            DSAs.push_back(dsa);

    }

    return DSAs;
}