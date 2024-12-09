void BioGearsSubstances::CalculateGenericExcretion(double VascularFlow_mL_Per_s, SETissueCompartment& tissue, SESubstance& sub, double FractionExcreted, double timestep_s, SEScalarMass* excreted)
{
  SELiquidSubstanceQuantity* subQ = m_data.GetCompartments().GetIntracellularFluid(tissue).GetSubstanceQuantity(sub);
  if (subQ == nullptr)
    throw CommonDataModelException("No Substance Quantity found for substance " + sub.GetName());
  double concentration_ug_Per_mL;
  SEScalarMassPerVolume concentration;
  if (sub.HasPK()) {
    GeneralMath::CalculateConcentration(subQ->GetMass(), tissue.GetMatrixVolume(), concentration, m_Logger);
    concentration_ug_Per_mL = concentration.GetValue(MassPerVolumeUnit::ug_Per_mL);
  } else {
    concentration_ug_Per_mL = subQ->GetConcentration(MassPerVolumeUnit::ug_Per_mL);
  }

  double MassExcreted_ug = VascularFlow_mL_Per_s * concentration_ug_Per_mL * timestep_s * 0.5 * FractionExcreted; //0.5  is the tuning parameter to remove the correct percentage.

  double mass_ug = subQ->GetMass().GetValue(MassUnit::ug);
  mass_ug = subQ->GetMass().GetValue(MassUnit::ug) - MassExcreted_ug;
  if (mass_ug < 0)
    mass_ug = 0;

  MassExcreted_ug = subQ->GetMass().GetValue(MassUnit::ug) - mass_ug;
  subQ->GetMass().SetValue(mass_ug, MassUnit::ug);
  subQ->Balance(BalanceLiquidBy::Mass);
  subQ->GetMassExcreted().IncrementValue(MassExcreted_ug, MassUnit::ug);
  if (excreted != nullptr)
    excreted->SetValue(MassExcreted_ug, MassUnit::ug);
}