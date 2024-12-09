void BioGearsSubstances::CalculateGenericClearance(double volumeCleared_mL, SELiquidCompartment& cmpt, SESubstance& sub, SEScalarMass* cleared)
{
  SELiquidSubstanceQuantity* subQ = cmpt.GetSubstanceQuantity(sub);
  if (subQ == nullptr)
    throw CommonDataModelException("No Substance Quantity found for substance " + sub.GetName());
  //GetMass and Concentration from the compartment
  double mass_ug = subQ->GetMass(MassUnit::ug);
  double concentration_ug_Per_mL = subQ->GetConcentration(MassPerVolumeUnit::ug_Per_mL);

  //Calculate Mass Cleared
  double MassCleared_ug = volumeCleared_mL * concentration_ug_Per_mL;
  //Ensure mass does not become negative
  mass_ug -= MassCleared_ug;
  if (mass_ug < 0) {
    mass_ug = 0;
  }

  MassCleared_ug = subQ->GetMass(MassUnit::ug) - mass_ug;
  subQ->GetMass().SetValue(mass_ug, MassUnit::ug);
  subQ->Balance(BalanceLiquidBy::Mass);

  sub.GetSystemicMassCleared().IncrementValue(MassCleared_ug, MassUnit::ug);
  if (cleared != nullptr)
    cleared->SetValue(MassCleared_ug, MassUnit::ug);
}