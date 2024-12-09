void Tissue::AlveolarPartialPressureGradientDiffusion(SEGasCompartment& pulmonary, SELiquidCompartment& vascular, SESubstance& sub, double DiffusingCapacityO2_mL_Per_s_mmHg, double timestep_s)
{
  SEGasSubstanceQuantity* pSubQ = pulmonary.GetSubstanceQuantity(sub);
  SELiquidSubstanceQuantity* vSubQ = vascular.GetSubstanceQuantity(sub);
  if (pSubQ == nullptr || vSubQ == nullptr)
    throw CommonDataModelException("No Substance Quantity found for substance " + sub.GetName());

  double PressureGradient_mmHg = pSubQ->GetPartialPressure(PressureUnit::mmHg) - vSubQ->GetPartialPressure(PressureUnit::mmHg);

  double DiffusedVolume_mL = PressureGradient_mmHg * DiffusingCapacityO2_mL_Per_s_mmHg * sub.GetRelativeDiffusionCoefficient().GetValue() * timestep_s;

  //Get special diffused volume if sub is CO
  if (PressureGradient_mmHg > 0 && &sub == m_CO) // Wants to come into the blood
  {
    DiffusedVolume_mL = PressureGradient_mmHg * DiffusingCapacityO2_mL_Per_s_mmHg * sub.GetRelativeDiffusionCoefficient().GetValue() * (1 / (5.404e-05 * vascular.GetSubstanceQuantity(*m_O2)->GetPartialPressure(PressureUnit::mmHg) + 0.02885)) * timestep_s; //Modify the relative diffusion coefficient
  }
  double DiffusedMass_ug = DiffusedVolume_mL * sub.GetDensity(MassPerVolumeUnit::ug_Per_mL);

  //Check to make sure we're not moving more than exists
  if (DiffusedVolume_mL > 0) {
    //It's moving from pulmonary to vascular
    double pVolume_mL = pSubQ->GetVolume(VolumeUnit::mL);
    if (DiffusedVolume_mL > pVolume_mL) {
      //Move all we can
      DiffusedVolume_mL = pVolume_mL;
      DiffusedMass_ug = DiffusedVolume_mL * sub.GetDensity(MassPerVolumeUnit::ug_Per_mL);
    }
  } else {
    //It's moving from vascular to pulmonary
    double vMass_ug = vSubQ->GetMass(MassUnit::ug);
    if (-DiffusedMass_ug > vMass_ug) {
      //Move all we can
      DiffusedMass_ug = -vMass_ug;
      DiffusedVolume_mL = DiffusedMass_ug / sub.GetDensity(MassPerVolumeUnit::ug_Per_mL);
    }
  }

  pSubQ->GetVolume().IncrementValue(-DiffusedVolume_mL, VolumeUnit::mL);
  sub.GetAlveolarTransfer().IncrementValue(DiffusedVolume_mL / timestep_s, VolumePerTimeUnit::mL_Per_s);
  sub.GetDiffusingCapacity().IncrementValue(DiffusingCapacityO2_mL_Per_s_mmHg * sub.GetRelativeDiffusionCoefficient().GetValue(), VolumePerTimePressureUnit::mL_Per_s_mmHg);

  vSubQ->GetMass().IncrementValue(DiffusedMass_ug, MassUnit::ug);
  if (std::abs(vSubQ->GetMass(MassUnit::ug)) < ZERO_APPROX) {
    vSubQ->GetMass().SetValue(0.0, MassUnit::ug);
  }
  vSubQ->Balance(BalanceLiquidBy::Mass);
}