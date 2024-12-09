void Tissue::ProteinStorageAndRelease()
{

  double aminoAcidsBaseline_mg_Per_dL = 50; // \todo make this a CDM set point like glucose?

  //Patients with diabetes type 2 show increased blood AA; allow for up to 30 mg/dL elevation in severe cases \cite guyton2006medical p989
  if (m_data.GetConditions().HasDiabetesType2()) {
    if (m_data.GetConditions().GetDiabetesType2()->HasInsulinResistanceSeverity()) {
      double increasedAA_mg_Per_dL = GeneralMath::LinearInterpolator(0, 1, 0, 30, m_data.GetConditions().GetDiabetesType2()->GetInsulinResistanceSeverity().GetValue());
      aminoAcidsBaseline_mg_Per_dL += increasedAA_mg_Per_dL;
    }
  }

  double hormoneFactor = Hepatic::CalculateRelativeHormoneChange(GetMuscleInsulinSetPoint().GetValue(AmountPerVolumeUnit::mmol_Per_L) * 1e9, GetMuscleGlucagonSetPoint().GetValue(MassPerVolumeUnit::mg_Per_mL) * 1e9, m_MuscleInsulin, m_MuscleGlucagon, m_data);

  //Guyton says protein blood concentrations should only rise 2-3 mg/dL even after eating because of absorption into tissues
  double proteinStorageLowerRate_g_Per_s = .3;
  double proteinStorageUpperRate_g_Per_s = .6;

  //https://www.wolframalpha.com/input/?i=y%3D.3%2B.3%2F(1%2Be%5E(-6(x-1)))+from+0%3Cy%3C.6+and+0%3Cx%3C2
  double proteinStorageRate_g_Per_s = proteinStorageLowerRate_g_Per_s + GeneralMath::LogisticFunction(proteinStorageUpperRate_g_Per_s - proteinStorageLowerRate_g_Per_s, 1, 6, hormoneFactor);

  //Assume protein breakdown rates are similar to storage rates, maybe a bit slower; could be adjusted
  double proteinBreakdownLowerRate_g_Per_s = .1;
  double proteinBreakdownUpperRate_g_Per_s = .2;

  //https://www.wolframalpha.com/input/?i=y%3D.1%2B.1%2F(1%2Be%5E(-15(x-.75)))+from+0%3Cy%3C.2+and+0%3Cx%3C2
  double proteinBreakdownRate_g_Per_s = proteinBreakdownLowerRate_g_Per_s + GeneralMath::LogisticFunction(proteinBreakdownUpperRate_g_Per_s - proteinBreakdownLowerRate_g_Per_s, .75, 15, -hormoneFactor);

  //Patients with COPD experience high protein turnover, so up the breakdown rate by a percentage \cite engelen2000enhanced
  if (m_data.GetConditions().HasChronicObstructivePulmonaryDisease()) {
    proteinBreakdownRate_g_Per_s *= 1.13; //13% increase
  }

  //remove excess amino acids from blood and store in muscle while there's room
  //Body mobilizes protein when glucagon dominates, but we'll have protein shift toward storage unless insulin drops significantly
  if (hormoneFactor >= -.2 && GetStoredProtein(MassUnit::g) < m_maxProteinStorage_g && m_MuscleAA->GetConcentration().GetValue(MassPerVolumeUnit::mg_Per_dL) > aminoAcidsBaseline_mg_Per_dL) {
    if (m_MuscleAA->GetMass(MassUnit::g) < proteinStorageRate_g_Per_s * m_Dt_s) {
      m_ss << "Not enough amino acids in blood to store!";
      Info(m_ss);
    } else {
      m_MuscleAA->GetMass().IncrementValue(-proteinStorageRate_g_Per_s * m_Dt_s, MassUnit::g);
      GetStoredProtein().IncrementValue(proteinStorageRate_g_Per_s * m_Dt_s, MassUnit::g);
      m_MuscleAA->Balance(BalanceLiquidBy::Mass);
    }

    //If we rise above 10% of protein storage, turn off the Muscle Catabolism event
    if (m_Patient->IsEventActive(CDM::enumPatientEvent::MuscleCatabolism) && GetStoredProtein(MassUnit::g) > .1 * m_maxProteinStorage_g) {
      m_Patient->SetEvent(CDM::enumPatientEvent::MuscleCatabolism, false, m_data.GetSimulationTime());
    }
  }

  //Remove amino acids from protein stores (or muscle if that's depleted) and dump into blood
  //We don't dump AA into blood if blood concentration is already at basal level
  else if (hormoneFactor < 0 && m_MuscleAA->GetConcentration().GetValue(MassPerVolumeUnit::mg_Per_dL) < aminoAcidsBaseline_mg_Per_dL) {
    //Muscle catabolism
    if (GetStoredProtein(MassUnit::g) < proteinBreakdownRate_g_Per_s * m_Dt_s) {
      if (!m_Patient->IsEventActive(CDM::enumPatientEvent::MuscleCatabolism)) {
        m_Patient->SetEvent(CDM::enumPatientEvent::MuscleCatabolism, true, m_data.GetSimulationTime());
      }
      if (m_Patient->GetMuscleMass(MassUnit::g) < proteinBreakdownRate_g_Per_s * m_Dt_s) {
        m_ss << "The patient has consumed all of their body's amino acids. They've effectively starved.";
        Warning(m_ss);
        m_Patient->SetEvent(CDM::enumPatientEvent::IrreversibleState, true, m_data.GetSimulationTime());
      } else {
        m_MuscleAA->GetMass().IncrementValue(proteinBreakdownRate_g_Per_s * m_Dt_s, MassUnit::g);
        m_Patient->GetMuscleMass().IncrementValue(-proteinBreakdownRate_g_Per_s * m_Dt_s, MassUnit::g);
        m_MuscleAA->Balance(BalanceLiquidBy::Mass);
      }
    }
    //Temporary protein storage used
    else {
      m_MuscleAA->GetMass().IncrementValue(proteinBreakdownRate_g_Per_s * m_Dt_s, MassUnit::g);
      GetStoredProtein().IncrementValue(-proteinBreakdownRate_g_Per_s * m_Dt_s, MassUnit::g);
      m_MuscleAA->Balance(BalanceLiquidBy::Mass);
    }
  }
}