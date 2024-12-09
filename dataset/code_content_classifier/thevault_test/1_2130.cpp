double Tissue::PerfusionLimitedDiffusion(SETissueCompartment& tissue, SELiquidCompartment& vascular, const SESubstance& sub, double partitionCoeff, double timestep_s)
{
  //Put an if statement here to check if tissue volume is nullptr, if so continue.

  SELiquidCompartment& intracellular = m_data.GetCompartments().GetIntracellularFluid(tissue);

  //Calculate Diffusion
  SELiquidSubstanceQuantity* vSubQ = vascular.GetSubstanceQuantity(sub);
  if (vSubQ == nullptr)
    throw CommonDataModelException("No Vascular Substance Quantity found for substance " + sub.GetName());
  double VascularFlow_m_LPer_s = vascular.GetInFlow(VolumePerTimeUnit::mL_Per_s);
  double VascularConcentration_ug_Per_mL = vSubQ->GetConcentration(MassPerVolumeUnit::ug_Per_mL);

  SELiquidSubstanceQuantity* tSubQ = intracellular.GetSubstanceQuantity(sub);
  if (tSubQ == nullptr)
    throw CommonDataModelException("No Tissue-Intracellular Substance Quantity found for substance " + sub.GetName());
  SEScalarMassPerVolume tissueConcentration;
  GeneralMath::CalculateConcentration(tSubQ->GetMass(), tissue.GetMatrixVolume(), tissueConcentration, m_Logger);
  double TissueConcentration_ug_Per_mL = tissueConcentration.GetValue(MassPerVolumeUnit::ug_Per_mL);
  double MassIncrement_ug = 0;
  if (!partitionCoeff == 0) {
    MassIncrement_ug = VascularFlow_m_LPer_s * timestep_s * (VascularConcentration_ug_Per_mL - (TissueConcentration_ug_Per_mL / partitionCoeff));
  } else {
    MassIncrement_ug = 0;
  }

  //Update the mass and concentration on the nodes
  if (MassIncrement_ug != 0) {
    // If it's going in, distribute by volume
    // If it's coming out, distribute by mass
    // If mass is exactly zero then going in by mass weighted won't work.
    if (MassIncrement_ug > 0.) {
      if (MassIncrement_ug > vSubQ->GetMass(MassUnit::ug))
        MassIncrement_ug = vSubQ->GetMass(MassUnit::ug);
      DistributeMassbyMassWeighted(vascular, sub, -MassIncrement_ug, MassUnit::ug);
      DistributeMassbyVolumeWeighted(intracellular, sub, MassIncrement_ug, MassUnit::ug);
    } else {
      if (-MassIncrement_ug > tSubQ->GetMass(MassUnit::ug))
        MassIncrement_ug = -tSubQ->GetMass(MassUnit::ug);
      DistributeMassbyVolumeWeighted(vascular, sub, -MassIncrement_ug, MassUnit::ug);
      DistributeMassbyMassWeighted(intracellular, sub, MassIncrement_ug, MassUnit::ug);
    }

    vSubQ->Balance(BalanceLiquidBy::Mass);
    tSubQ->Balance(BalanceLiquidBy::Mass);
  }
  return MassIncrement_ug;
}