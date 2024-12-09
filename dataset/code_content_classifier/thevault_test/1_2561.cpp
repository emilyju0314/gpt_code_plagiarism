void cdi_eospac_tpack(rtt_dsxx::UnitTest &ut) {
  // Start the test.
  std::cout << "\nTest the pack() function for cdi_eospac().\n" << std::endl;

  int const Al3717 = 3717;
  int const Al23714 = 23714;
  rtt_cdi_eospac::SesameTables AlSt;
  AlSt.Uic_DT(Al3717).Ktc_DT(Al23714).Ue_DT(Al3717).Zfc_DT(Al23714);
  std::shared_ptr<rtt_cdi_eospac::Eospac const> spEospac(new rtt_cdi_eospac::Eospac(AlSt));

  {
    // Test the SesameTables packer
    std::cout << "Packing a SesameTables object." << std::endl;
    std::vector<char> packed(AlSt.pack());

    // Create a new SesameTables by unpacking the packed data
    std::cout << "Unpacking a SesameTables object." << std::endl;
    rtt_cdi_eospac::SesameTables unpacked_AlSt(packed);

    if (AlSt.matID(EOS_Uic_DT) == unpacked_AlSt.matID(EOS_Uic_DT))
      PASSMSG("unpacked AlSt looks okay.");
    else
      FAILMSG("unpacked AlSt is wrong!");
  }

  {
    // Test the Eospac packer.
    std::cout << "Packing an Eospac object." << std::endl;
    std::vector<char> packed(spEospac->pack());

    // Create a new Eospac by unpacking the packed data.
    std::cout << "Unpacking an Eospac object." << std::endl;
    std::shared_ptr<rtt_cdi_eospac::Eospac const> spUnpacked_Eospac(
        new rtt_cdi_eospac::Eospac(packed));

    // Sanity Check
    double density = 5.0;     // g/cm^3
    double temperature = 0.1; // keV

    double cvi1(spEospac->getSpecificIonInternalEnergy(temperature, density));
    double cvi2(spUnpacked_Eospac->getSpecificIonInternalEnergy(temperature, density));
    if (soft_equiv(cvi1, cvi2, 1.0e-10))
      PASSMSG("unpacked spEospac looks okay.");
    else
      FAILMSG("unpacked spEospac is wrong.");
  }

  return;
}