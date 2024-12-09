int CpuemShim::xclIPName2Index(const char *name)
{ 
  //Get IP_LAYOUT buffer from xclbin
  auto buffer = mCoreDevice->get_axlf_section(IP_LAYOUT);
  return xclemulation::getIPName2Index(name, buffer.first);
}