CSK_Interface::CSK_Interface(const std::string &filehandle, const std::vector<double> &grp_bds,
                             const std::string &opac_type, const std::string &wt_func,
                             const bool induced, const bool det_bal, const size_t nxi) {

  // Check input validity
  Require(std::ifstream(filehandle).good());
  Require(grp_bds.size() > 0);

  if (rtt_c4::node() == 0) {
    std::cout << "*********************************************************\n"
              << "WARNING! Building a multigroup library from scratch might\n"
              << " take a LOOOOOOONG time! (Don't say I didn't warn you.)  \n"
              << "*********************************************************\n"
              << std::endl;
  }

  // do quick sanity check
  if (det_bal) {
    // if we're enforcing detailed balance, we need induced and wt_func to be set to
    // <0,"wien">||<1,"planck">; these are the only valid cases
    Insist(((!induced && wt_func == std::string("wien")) ||
            (induced && wt_func == std::string("planck"))),
           "CSK_Interface error: Detailed balance enforcement (det_bal = 1) \n"
           "only valid for induced=0 w/wien -OR- induced=1 w/planck!");
  }

  // make a group_data struct to pass to the lib builder:
  multigroup::Group_data grp_data = {multigroup::Library_type::EXISTING,
                                     multigroup::string_to_opac_type(opac_type),
                                     multigroup::string_to_wt_func(wt_func),
                                     induced,
                                     det_bal,
                                     filehandle,
                                     nxi,
                                     grp_bds};

  // Construct a multigroup library builder:
  multigroup_lib_builder MG_builder(grp_data, rtt_c4::node());

  // build the library:
  MG_builder.build_library();

  // initialize the electron temperature interpolator with the mg compton data
  ei = std::make_unique<etemp_interp>(MG_builder.package_data());

  // Make sure the SP exists...
  Ensure(ei);
}