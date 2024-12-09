static int 
updateShellAndSC(unsigned int  boardIdx, DSAInfo& candidate, bool& reboot)
{
  reboot = false;

  Flasher flasher(boardIdx);

  bool same_dsa = false;
  bool same_bmc = false;
  DSAInfo current = flasher.getOnBoardDSA();
  if (!current.name.empty()) {
    same_dsa = (candidate.name == current.name &&
      candidate.matchId(current));

    // Always update Arista devices
    if (candidate.vendor_id == ARISTA_ID)
        same_dsa = false;

    // getOnBoardDSA() returns an empty bmcVer in the case there is no SC,
    // so do not update
    if (current.bmcVer.empty())
        same_bmc = true;
    else
        same_bmc = (candidate.bmcVer == current.bmcVer);
  }
  if (same_dsa && same_bmc) {
    std::cout << "update not needed" << std::endl;
    return 0;
  }

  if (!same_bmc) {
    std::cout << "Updating SC firmware on card[" << flasher.sGetDBDF() <<
      "]" << std::endl;
    update_SC(boardIdx, candidate.file);
  }

  if (!same_dsa) {
    std::cout << boost::format("[%s] : Updating shell\n") % flasher.sGetDBDF();
    update_shell(boardIdx, candidate.file, candidate.file);
    reboot = true;
  }

  if (!same_dsa && !reboot)
    return -EINVAL;

  return 0;
}