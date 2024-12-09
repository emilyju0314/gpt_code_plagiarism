void Tissue::CalculateTissueFluidFluxes()
{
  SETissueCompartment* tissue;
  SEFluidCircuitPath* osmoticFlow;

  double naIntra_mM = 0.0;
  double naExtra_mM = 0.0;
  double kIntra_mM = 0.0;
  double kExtra_mM = 0.0;
  double clIntra_mM = 0.0;
  double clExtra_mM = 0.0;
  double mOsmIntra = 0.0;
  double mOsmExtra = 0.0;
  double hydraulicConductivity_mL_Per_min_mM = 0.0;
  double proteinIntra_mM = 112.0; //Need this to get osmotically stable cell with the desired ion concentrations
  double intracellularVolumeBaseline_mL = 0.0;
  double intracellularVolume_mL = 0.0;
  double extracellularVolumeBaseline_mL = 0.0;
  double extracellularVolume = 0.0;

  double lymphFlow_mL_Per_s = 0.0;
  double lymphFlowBaseline_mL_Per_s = 0.0;
  double extracellularCompliance_mL_Per_mmHg = 0.0;

  for (auto flowPath : m_ExtraToIntraPaths) {
    tissue = flowPath.first;
    osmoticFlow = flowPath.second;

    SELiquidCompartment& extracellular = m_data.GetCompartments().GetExtracellularFluid(*tissue);
    SELiquidCompartment& intracellular = m_data.GetCompartments().GetIntracellularFluid(*tissue);

    intracellularVolumeBaseline_mL = osmoticFlow->GetTargetNode().GetVolumeBaseline(VolumeUnit::mL);
    intracellularVolume_mL = intracellular.GetVolume(VolumeUnit::mL);
    hydraulicConductivity_mL_Per_min_mM = 0.3 * tissue->GetTotalMass(MassUnit::kg); //Carlson has units of mL/min-kg-mmol --> multiply by tissue mass up front

    naIntra_mM = intracellular.GetSubstanceQuantity(*m_Sodium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
    naExtra_mM = extracellular.GetSubstanceQuantity(*m_Sodium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
    kIntra_mM = intracellular.GetSubstanceQuantity(*m_Potassium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
    kExtra_mM = extracellular.GetSubstanceQuantity(*m_Potassium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
    clIntra_mM = intracellular.GetSubstanceQuantity(*m_Chloride)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
    clExtra_mM = extracellular.GetSubstanceQuantity(*m_Chloride)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);

    mOsmIntra = naIntra_mM + kIntra_mM + clIntra_mM + proteinIntra_mM * (intracellularVolumeBaseline_mL / intracellularVolume_mL);
    mOsmExtra = naExtra_mM + kExtra_mM + clExtra_mM;

    osmoticFlow->GetNextFlowSource().SetValue(hydraulicConductivity_mL_Per_min_mM * (mOsmIntra - mOsmExtra), VolumePerTimeUnit::mL_Per_min);
  }
}