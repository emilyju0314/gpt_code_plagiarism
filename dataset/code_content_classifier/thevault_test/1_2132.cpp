double Tissue::MoveMassByInstantDiffusion(SELiquidCompartment& source, SELiquidCompartment& target, const SESubstance& sub, double timestep_s)
{
  const SELiquidSubstanceQuantity* srcQ = source.GetSubstanceQuantity(sub);
  const SELiquidSubstanceQuantity* tgtQ = target.GetSubstanceQuantity(sub);

  double sConc_ug_Per_mL = srcQ->GetConcentration(MassPerVolumeUnit::ug_Per_mL);
  double tConc_ug_Per_mL = tgtQ->GetConcentration(MassPerVolumeUnit::ug_Per_mL);
  double sVol_mL = source.GetVolume(VolumeUnit::mL);
  double tVol_mL = target.GetVolume(VolumeUnit::mL);

  double amountIncrement_ug = (sConc_ug_Per_mL - tConc_ug_Per_mL) * (sVol_mL * tVol_mL) / (sVol_mL + tVol_mL);

  if (amountIncrement_ug > 0.0) {
    if (amountIncrement_ug > srcQ->GetMass(MassUnit::ug)) {
      amountIncrement_ug = srcQ->GetMass(MassUnit::ug);
    }
    DistributeMassbyMassWeighted(source, sub, -amountIncrement_ug, MassUnit::ug);
    DistributeMassbyVolumeWeighted(target, sub, amountIncrement_ug, MassUnit::ug);
  } else // negative increment means it is coming from the target and going to the source
  {
    if (-amountIncrement_ug > tgtQ->GetMass(MassUnit::ug)) {
      amountIncrement_ug = -tgtQ->GetMass(MassUnit::ug);
    }
    DistributeMassbyVolumeWeighted(source, sub, -amountIncrement_ug, MassUnit::ug);
    DistributeMassbyMassWeighted(target, sub, amountIncrement_ug, MassUnit::ug);
  }

  // Note we are only changing mass and NOT balancing on purpose
  // We don't want the concentrations changing until we have completed our
  // diffusion methodology in its entirety

  return amountIncrement_ug;
}