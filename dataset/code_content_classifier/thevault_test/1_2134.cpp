void Tissue::CoupledIonTransport(SETissueCompartment& tissue, SELiquidCompartment& extra, SELiquidCompartment& intra, SELiquidCompartment& vascular)
{
  //All terms are on the basis of a single cell using model from Yi2003Mathematical--these will be converted to macro level using reported cell volume/surface area ratio from same source
  double faradaysConstant_C_Per_mol = 96485;
  double idealGasConstant = 8.314; //Amazingly, R has same value in J/mol-K and mL-Pa/K-umol
  double temperature_K = 310.0; //Replace w/ call to body temperature
  double membranePotential_V = tissue.GetMembranePotential(ElectricPotentialUnit::V);
  double cellSurfaceArea_cm2 = 7.7e-5; //From Yi2003Mathematical
  double scaleFactor = tissue.GetTotalMass(MassUnit::kg) * 1e6 / cellSurfaceArea_cm2; //Carlson reports 1*10^6 cm^2 / kg tissue relationship

  //Get all ion concentrations
  double naExtracellular_mM = extra.GetSubstanceQuantity(*m_Sodium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  double naIntracellular_mM = intra.GetSubstanceQuantity(*m_Sodium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  double kExtracellular_mM = extra.GetSubstanceQuantity(*m_Potassium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  double kIntracellular_mM = intra.GetSubstanceQuantity(*m_Potassium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  double clExtracellular_mM = extra.GetSubstanceQuantity(*m_Chloride)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  double clIntracellular_mM = intra.GetSubstanceQuantity(*m_Chloride)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  //double calciumExtracellular_mM = extra.GetSubstanceQuantity(*m_Calcium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);
  //double calciumIntracellular_mM = intra.GetSubstanceQuantity(*m_Calcium)->GetMolarity(AmountPerVolumeUnit::mmol_Per_L);

  /// \ @cite lindblad 1996model
  double naConductance_mC_Per_V_min = 2.925e-5;
  double kConductance_mC_Per_V_min = 7.0e-4;
  double clConductance_mC_Per_V_min = 2.81e-4;
  //double calciumConductance_S_Per_mL = 1.0 / (m_Calcium->GetMembraneResistance(ElectricResistanceUnit::Ohm));

  //Calculate current Nernst potentials for each ion (Faradays constant is multiplied by the charge of the ion--1 for Na and K, -1 for Cl)
  double coreTemp_K = m_data.GetEnergy().GetCoreTemperature(TemperatureUnit::K);
  double naNernst_V = GeneralMath::CalculateNernstPotential(extra, intra, m_Sodium, coreTemp_K);
  double kNernst_V = GeneralMath::CalculateNernstPotential(extra, intra, m_Potassium, coreTemp_K);
  double clNernst_V = GeneralMath::CalculateNernstPotential(extra, intra, m_Chloride, coreTemp_K);
  //double calciumNernst_V = CalculateNernstPotential(extra, intra, m_Calcium, coreTemp_K);

  //Calculate pump rate using information from previous time step--this will lag a time step behind everything but it
  //shouldn't make a huge difference
  double NaKPumpRate_umol_Per_min = SodiumPotassiumPump(naIntracellular_mM, naExtracellular_mM, kExtracellular_mM, membranePotential_V);

  //Calculate new membrane potential (uses previous pump rate)
  membranePotential_V = (naConductance_mC_Per_V_min * naNernst_V + kConductance_mC_Per_V_min * kNernst_V + clConductance_mC_Per_V_min * clNernst_V - faradaysConstant_C_Per_mol * NaKPumpRate_umol_Per_min / 1000.0) / (naConductance_mC_Per_V_min + kConductance_mC_Per_V_min + clConductance_mC_Per_V_min);
  tissue.GetMembranePotential().SetValue(membranePotential_V, ElectricPotentialUnit::V);

  //Calculate diffusion fluxes of each ion through channels in umol/min with respect to intracellular compartment
  //Units:  1000 factor converts mol/C to umol/mC
  double naFlux_umol_Per_min = -((1000.0 * naConductance_mC_Per_V_min / faradaysConstant_C_Per_mol) * (membranePotential_V - naNernst_V) + 3 * NaKPumpRate_umol_Per_min);
  double kFlux_umol_Per_min = -((1000.0 * kConductance_mC_Per_V_min / faradaysConstant_C_Per_mol) * (membranePotential_V - kNernst_V) - 2 * NaKPumpRate_umol_Per_min);
  double clFlux_umol_Per_min = (1000.0 * clConductance_mC_Per_V_min / faradaysConstant_C_Per_mol) * (membranePotential_V - clNernst_V);
  //double calciumDiffusion_mol_Per_mL_s = calciumConductance_S_Per_mL*(membranePotential_V - calciumNernst_V) / (faradaysConstant_C_Per_mol * 2);

  //This commented out block of code takes regulatory volume increase and decrease into account.  In essence, cells can rapidly transport
  //ions through channels to oppose a change in volume caused by a large change in osmotic environment.  It's not clear if we need this as of now
  //but the code is here if we want to turn it on.

  //These constants from Hernandez1998Modeling are used to determined regulatory volume increase/decrease.
  //Boundaries are from Hoffman1989Membrane

  /*double qNa_mL6_Per_umol_min = 0.1 * 1.0e-6 * 60.0 * cellSurfaceArea_cm2;    //Value reported = 0.1 mL^4/mol-s --> Convert to mL^6/umol-min to fit with units later on
        double qK_mL6_Per_umol_min = 10.0 * 1.0e-6 * 60.0 * cellSurfaceArea_cm2;
        double volLimitUpper_mL = 1.01*intracellularVolumeBaseline_mL;
        double volLimitLower_mL = 0.99*intracellularVolumeBaseline_mL;
        if (intracellularVolume_mL <= volLimitLower_mL)
        {
          qNa_mL6_Per_umol_min *= (volLimitLower_mL - intracellularVolume_mL) / volLimitLower_mL;
          qK_mL6_Per_umol_min = 0.0;
        }
        else if (intracellularVolume_mL >= volLimitUpper_mL)
        {
          qNa_mL6_Per_umol_min = 0.0;
          qK_mL6_Per_umol_min *= (intracellularVolume_mL - volLimitUpper_mL) / volLimitUpper_mL;
        }
        else
        {
          qNa_mL6_Per_umol_min = 0.0;
          qK_mL6_Per_umol_min = 0.0;
        }

        double psiNa_umol_Per_min = qNa_mL6_Per_umol_min*(naExtracellular_mM*clExtracellular_mM - naIntracellular_mM*clIntracellular_mM);
        double psiK_umol_Per_min = qK_mL6_Per_umol_min*(kExtracellular_mM*clExtracellular_mM - kIntracellular_mM*clIntracellular_mM);

        naFlux_umol_Per_min += psiNa_umol_Per_min;
        kFlux_umol_Per_min += psiK_umol_Per_min;
        clFlux_umol_Per_min += (psiNa_umol_Per_min + psiK_umol_Per_min);*/
  //Cl flux is coupled to both of these process to maintain electroneutrality

  //End of optional RVI/RVD functionality

  //Here is what we actually move at each time step, based on the calculated rate, and scaled up from cellular level to tissue
  double naIncrement_ug = (naFlux_umol_Per_min * m_Sodium->GetMolarMass(MassPerAmountUnit::g_Per_mol)) * (m_Dt_s / 60) * scaleFactor;
  double kIncrement_ug = (kFlux_umol_Per_min * m_Potassium->GetMolarMass(MassPerAmountUnit::g_Per_mol)) * (m_Dt_s / 60) * scaleFactor;
  double clIncrement_ug = (clFlux_umol_Per_min * m_Chloride->GetMolarMass(MassPerAmountUnit::g_Per_mol)) * (m_Dt_s / 60) * scaleFactor;

  SESubstance* ion;
  double incrementer_ug = 0.0;
  double toVascular_ug = 0.0;
  std::map<SESubstance*, double> ionIncrements = { { m_Sodium, naIncrement_ug }, { m_Potassium, kIncrement_ug }, { m_Chloride, clIncrement_ug } };
  for (auto ions : ionIncrements) {
    ion = ions.first;
    incrementer_ug = ions.second;

    if (incrementer_ug > 0) {
      //Net flux is direction extra-->intra
      if (incrementer_ug > extra.GetSubstanceQuantity(*ion)->GetMass(MassUnit::ug)) {
        //Make sure we don't take it more than is there (shouldn't happen but you never know)
        incrementer_ug = extra.GetSubstanceQuantity(*ion)->GetMass(MassUnit::ug);
      }
      DistributeMassbyMassWeighted(extra, *ion, -incrementer_ug, MassUnit::ug);
      DistributeMassbyVolumeWeighted(intra, *ion, incrementer_ug, MassUnit::ug);
    } else {
      //Net flux is direction intra-->extra
      if (-incrementer_ug > intra.GetSubstanceQuantity(*ion)->GetMass(MassUnit::ug)) {
        incrementer_ug = -intra.GetSubstanceQuantity(*ion)->GetMass(MassUnit::ug);
      }
      DistributeMassbyVolumeWeighted(extra, *ion, -incrementer_ug, MassUnit::ug);
      DistributeMassbyMassWeighted(intra, *ion, incrementer_ug, MassUnit::ug);
    }
    //Balancing will happen in CalcDiffusion method after transport from vascular to extracellular is handled for each ion.
  }
}