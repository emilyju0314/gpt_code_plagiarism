void Tissue::ManageSubstancesAndSaturation()
{
  SEScalarMassPerVolume albuminConcentration;
  albuminConcentration.SetValue(45.0, MassPerVolumeUnit::g_Per_L);
  // Currently, substances are not where they need to be, we will hard code this for now until we fix them
  /// \todo Remove SetBodyState hardcode and replace with computed values after substance redux is complete
  m_data.GetSaturationCalculator().SetBodyState(albuminConcentration,
    m_data.GetBloodChemistry().GetHematocrit(),
    m_data.GetEnergy().GetCoreTemperature(),
    m_data.GetBloodChemistry().GetStrongIonDifference(),
    m_data.GetBloodChemistry().GetPhosphate());
  for (SELiquidCompartment* cmpt : m_data.GetCompartments().GetVascularLeafCompartments()) {
    if (cmpt->HasVolume()) {
      m_data.GetSaturationCalculator().CalculateBloodGasDistribution(*cmpt);
    }
  }
}