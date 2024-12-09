CSK_Interface::CSK_Interface(const std::string &filehandle, const bool llnl_style) {

  // Make a compton_interface file object to read the multigroup data
  compton_file Cfile(false);
  if (llnl_style) {
    // initialize the etemp/frequency interpolated with the library data:
    llnli = std::make_unique<llnl_interp>(Cfile.read_llnl_data(filehandle));
    // Make sure the SP exists...
    Ensure(llnli);
  } else {
    // initialize the electron temperature interpolator with the mg compton data
    ei = std::make_unique<etemp_interp>(Cfile.read_mg_csk_data(filehandle));
    // Make sure the SP exists...
    Ensure(ei);
  }
}