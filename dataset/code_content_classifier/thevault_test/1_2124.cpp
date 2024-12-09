void Tissue::Process()
{
  ProteinStorageAndRelease();
  FatStorageAndRelease();
  CalculateMetabolicConsumptionAndProduction(m_Dt_s);
  CalculatePulmonaryCapillarySubstanceTransfer();
  CalculateDiffusion();
  ManageSubstancesAndSaturation();
  CalculateVitals();
}