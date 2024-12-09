void Tissue::FatStorageAndRelease()
{
  double triacylglycerolBaseline_mg_Per_dL = 75; // \todo make this a CDM set point like glucose?

  double hormoneFactor = Hepatic::CalculateRelativeHormoneChange(GetFatInsulinSetPoint().GetValue(AmountPerVolumeUnit::mmol_Per_L) * 1e9, GetFatGlucagonSetPoint().GetValue(MassPerVolumeUnit::mg_Per_mL) * 1e9, m_FatInsulin, m_FatGlucagon, m_data);

  //Guyton says triglycerides in chylomicrons are clear from blood in "a few hours" with chylomicrons having half-life <1 hour
  //Other sources show triglycerides returning to normal in ~4 hours after peak
  //These values currently allow 75g of fat to be absorbed into bloodstream in ~4 hours, with all being stored in ~6 hours
  //Peak triglyceride levels are about 5x normal, maybe too high
  double fatStorageLowerRate_g_Per_s = .004;
  double fatStorageUpperRate_g_Per_s = .012;

  //https://www.wolframalpha.com/input/?i=y%3D.4%2B.8%2F(1%2Be%5E(-6(x-.5)))+from+0%3Cy%3C1.2+and+0%3Cx%3C2
  double fatStorageRate_g_Per_s = fatStorageLowerRate_g_Per_s + GeneralMath::LogisticFunction(fatStorageUpperRate_g_Per_s - fatStorageLowerRate_g_Per_s, 1, 6, hormoneFactor);

  //Assume fat release rates are similar to glycogen for now... but this could be revisited
  double fatReleaseLowerRate_g_Per_s = .002546; //maxStoredProtein_g/ 12 * 3600
  double fatReleaseUpperRate_g_Per_s = .061111; //maxStoredProtein_g/ .5 * 3600

  //https://www.wolframalpha.com/input/?i=y%3D.002546%2B.058565%2F(1%2Be%5E(-15(x-.75)))+from+0%3Cy%3C.08+and+0%3Cx%3C2
  double fatReleaseRate_g_Per_s = fatReleaseLowerRate_g_Per_s + GeneralMath::LogisticFunction(fatReleaseUpperRate_g_Per_s - fatReleaseLowerRate_g_Per_s, .75, 15, -hormoneFactor);

  //remove excess triacylglycerol from blood and store in fat tissue
  if (hormoneFactor >= -.2 && m_FatTAG->GetConcentration().GetValue(MassPerVolumeUnit::mg_Per_dL) > triacylglycerolBaseline_mg_Per_dL) {
    if (m_FatTAG->GetMass(MassUnit::g) < fatStorageRate_g_Per_s * m_Dt_s) {
      m_ss << "Not enough triacylglycerol in blood to store!";
      Info(m_ss);
    } else {
      m_FatTAG->GetMass().IncrementValue(-fatStorageRate_g_Per_s * m_Dt_s, MassUnit::g);
      GetStoredFat().IncrementValue(fatStorageRate_g_Per_s * m_Dt_s, MassUnit::g);
      m_FatTAG->Balance(BalanceLiquidBy::Mass);
    }
  }

  //remove triacylglycerol from fat stores and dump into blood
  //Guyton says during starvation (i.e. glucagon dominant times) triacylglycerol blood concentration can be 5-8x normal
  //We won't continue to dump TAG into blood if blood concentration is already high, but we will try to maintain base level
  else if ((hormoneFactor < 0 && m_FatTAG->GetConcentration().GetValue(MassPerVolumeUnit::mg_Per_dL) < triacylglycerolBaseline_mg_Per_dL * 6.5) || m_FatTAG->GetConcentration().GetValue(MassPerVolumeUnit::mg_Per_dL) < triacylglycerolBaseline_mg_Per_dL) {
    if (GetStoredFat(MassUnit::g) < fatReleaseRate_g_Per_s * m_Dt_s) {
      m_ss << "The patient has consumed all of their body's fat. They've effectively starved.";
      Warning(m_ss);
      m_Patient->SetEvent(CDM::enumPatientEvent::IrreversibleState, true, m_data.GetSimulationTime());
    } else {
      m_FatTAG->GetMass().IncrementValue(fatReleaseRate_g_Per_s * m_Dt_s, MassUnit::g);
      GetStoredFat().IncrementValue(-fatReleaseRate_g_Per_s * m_Dt_s, MassUnit::g);
      m_FatTAG->Balance(BalanceLiquidBy::Mass);
    }
  }
}