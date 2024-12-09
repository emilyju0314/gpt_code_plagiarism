void Tissue::CalculateOncoticPressure()
{
  //We don't want to mess with the pressure sources on the circuit until stabilization has been completed

  if (m_data.GetState() < EngineState::AtInitialStableState) {
    return;
  }
  SETissueCompartment* tissue;
  SELiquidCompartment* vascular;
  SEFluidCircuitPath* vascularCOP;
  SEFluidCircuitPath* interstitialCOP;
  double albuminMassInBlood_g = m_Albumin->GetMassInBlood(MassUnit::g);
  //Albumin mass in tissue is only in the extracellular space because we set albumin to 0 in intracellular and do not diffuse it across cell membrane.
  double albuminMassInTissue_g = m_Albumin->GetMassInTissue(MassUnit::g);
  double vascularVolume_dL = m_data.GetCardiovascular().GetBloodVolume(VolumeUnit::dL);
  double interstitialVolume_dL = 0.0;

  for (auto tissueVascular : m_TissueToVascular) {
    tissue = tissueVascular.first;
    interstitialVolume_dL += m_data.GetCompartments().GetExtracellularFluid(*tissue).GetVolume(VolumeUnit::dL);
  }

  double albuminVascularAvg_g_Per_dL = albuminMassInBlood_g / vascularVolume_dL;
  double albuminInterstitialAvg_g_Per_dL = albuminMassInTissue_g / interstitialVolume_dL;
  double albuminTotalAvg_g_Per_dL = (albuminMassInTissue_g + albuminMassInBlood_g) / (vascularVolume_dL + interstitialVolume_dL);

  ////In calculating oncotic pressure, we assume a linear relationship between plasma albumin concentration and total plasma protein
  ////concentration.  We then use the Landis-Pappenheimer (LP) Equation for total protein.  In the interstitial space, we assume that
  ////albumin is the only large protein present in significant quantities and use the correlation between albumin concentration and
  ////oncotic pressure reported by LP.  This assumes a healthy state where no other proteins are leaking across membrane.  Thus, these
  ////assumptions should change in hemorrhage and sepsis.
  ///// \ToDo:  Adjust protein concentration calculations to consider effect of damaged microvasculature
  double reflectionCoefficient = 0.0;
  double vascularOncoticPressure_mmHg = 0.0;
  double interstitialOncoticPressure_mmHg = 0.0;
  double effectiveVascular_g_Per_dL = 0.0;
  double effectiveInterstitial_g_Per_dL = 0.0;

  for (auto tissueVascular : m_TissueToVascular) {
    tissue = tissueVascular.first;
    vascular = tissueVascular.second;
    if (tissue->GetName() == BGE::TissueCompartment::Brain)
      continue;
    if (vascular->GetName() == BGE::VascularCompartment::LeftKidney)
      vascular = m_data.GetCompartments().GetLiquidCompartment(BGE::VascularCompartment::LeftRenalArtery);
    if (vascular->GetName() == BGE::VascularCompartment::RightKidney)
      vascular = m_data.GetCompartments().GetLiquidCompartment(BGE::VascularCompartment::RightRenalArtery);

    reflectionCoefficient = m_data.GetCompartments().GetTissueCompartment(tissue->GetName())->GetReflectionCoefficient().GetValue();
    LLIM(reflectionCoefficient, 0.05);
    effectiveVascular_g_Per_dL = 1.6 * GeneralMath::LinearInterpolator(0.0, 1.0, albuminTotalAvg_g_Per_dL, albuminVascularAvg_g_Per_dL, reflectionCoefficient);
    vascularOncoticPressure_mmHg = 2.1 * effectiveVascular_g_Per_dL + 0.16 * pow(effectiveVascular_g_Per_dL, 2) + 0.009 * pow(effectiveVascular_g_Per_dL, 3);
    if (vascular->GetName() == BGE::VascularCompartment::Gut) {
      for (auto c : vascular->GetChildren()) {
        vascularCOP = m_VascularCopPaths[c];
        vascularCOP->GetNextPressureSource().SetValue(-vascularOncoticPressure_mmHg, PressureUnit::mmHg);
      }
    } else {
      vascularCOP = m_VascularCopPaths[vascular];
      vascularCOP->GetNextPressureSource().SetValue(-vascularOncoticPressure_mmHg, PressureUnit::mmHg);
    }

    effectiveInterstitial_g_Per_dL = 1.6 * GeneralMath::LinearInterpolator(0.0, 1.0, albuminTotalAvg_g_Per_dL, albuminInterstitialAvg_g_Per_dL, reflectionCoefficient);
    interstitialOncoticPressure_mmHg = 2.1 * effectiveInterstitial_g_Per_dL + 0.16 * pow(effectiveInterstitial_g_Per_dL, 2) + 0.009 * pow(effectiveInterstitial_g_Per_dL, 3);
    interstitialCOP = m_InterstitialCopPaths[tissue];
    interstitialCOP->GetNextPressureSource().SetValue(interstitialOncoticPressure_mmHg, PressureUnit::mmHg);
  }
}