double Tissue::MoveMassByActiveTransport(SELiquidCompartment& source, SELiquidCompartment& target, const SESubstance& sub, double pumpRate_g_Per_s, double timestep_s)
{
  const SELiquidSubstanceQuantity* srcQ = source.GetSubstanceQuantity(sub);
  const SELiquidSubstanceQuantity* tgtQ = target.GetSubstanceQuantity(sub);

  double amountIncrement_g = pumpRate_g_Per_s * timestep_s;

  if (amountIncrement_g > 0.0) {
    if (amountIncrement_g > srcQ->GetMass(MassUnit::g)) {
      amountIncrement_g = srcQ->GetMass(MassUnit::g);
    }
    DistributeMassbyMassWeighted(source, sub, -amountIncrement_g, MassUnit::g);
    DistributeMassbyVolumeWeighted(target, sub, amountIncrement_g, MassUnit::g);
  } else // negative increment means it is coming from the target and going to the source
  {
    if (-amountIncrement_g > tgtQ->GetMass(MassUnit::g)) {
      amountIncrement_g = -tgtQ->GetMass(MassUnit::g);
    }
    DistributeMassbyVolumeWeighted(source, sub, -amountIncrement_g, MassUnit::g);
    DistributeMassbyMassWeighted(target, sub, amountIncrement_g, MassUnit::g);
  }

  // Note we are only changing mass and NOT balancing on purpose
  // We don't want the concentrations changing until we have completed our
  // diffusion methodology in its entirety

  return amountIncrement_g;
}