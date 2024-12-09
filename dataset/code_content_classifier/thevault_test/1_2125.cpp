void Tissue::CalculateDiffusion()
{
  SETissueCompartment* tissue;
  SELiquidCompartment* vascular;
  const SESubstanceTissuePharmacokinetics* tissueKinetics;
  for (auto tissueVascular : m_TissueToVascular) {
    tissue = tissueVascular.first;
    vascular = tissueVascular.second;
    SELiquidCompartment& extracellular = m_data.GetCompartments().GetExtracellularFluid(*tissue);
    SELiquidCompartment& intracellular = m_data.GetCompartments().GetIntracellularFluid(*tissue);
    //The extracellular to intracellular transport of the ions Na, K, Cl, and Ca are handled by the CoupledIonTransport method
    CoupledIonTransport(*tissue, extracellular, intracellular, *vascular);
    for (const SESubstance* sub : m_data.GetCompartments().GetLiquidCompartmentSubstances()) {
      double moved_ug; //used only for possible debugging output
      tissueKinetics = nullptr;
      if (sub->HasPK())
        tissueKinetics = sub->GetPK()->GetTissueKinetics(tissue->GetName());
      //Check to see if substance is a drug with the appropriate parameters to calculate PK diffusion
      // If the substance is a PBPK drug, then diffusion is computed by perfusion limited diffusion, as described in \cite huisinga2012modeling
      if (tissueKinetics != nullptr) {
        if (!tissueKinetics->HasPartitionCoefficient()) {
          Error("Attempted to diffuse a substance with PK that had no partition coefficient available.");
          continue;
        }
        PerfusionLimitedDiffusion(*tissue, *vascular, *sub, tissueKinetics->GetPartitionCoefficient(), m_Dt_s); //Balance happens in the method
      }
      // Otherwise, the diffusion is computed by either:
      // Instantaneous diffusion, Simple diffusion, Facilitated diffusion, or Active diffusion
      else {

        //We have to make an exception for the brain and TAGs, since TAG can't cross blood-brain barrier
        if (sub->GetName() == "Triacylglycerol" && extracellular.GetName().find("Brain") != std::string::npos)
          continue;

        //Gases get moved by instant diffusion
        if (sub->GetState() == CDM::enumSubstanceState::Gas) {
          //Vascular to Extracellular
          moved_ug = MoveMassByInstantDiffusion(*vascular, extracellular, *sub, m_Dt_s);

          //Extracellular to Intracellular
          moved_ug = MoveMassByInstantDiffusion(extracellular, intracellular, *sub, m_Dt_s);
        }
        //Bicarbonate doesn't diffuse because it is charged
        else if (sub->GetName() != "Bicarbonate") {
          double molarMass_g_Per_mol = sub->GetMolarMass(MassPerAmountUnit::g_Per_mol);

          //Simple diffusion calculates a permeability based on molecular weight. Even large molecules will diffuse, though slowly.
          //We want to prevent movement of large molecules like proteins completely. A gate of 1000 g/mol will filter out things like
          //albumin, insulin, etc while allowing glucose, ions, and others to be governed by their molecular weight.
          //Note: it doesn't consider lipophilicity, so TAG will need to be artificially tweaked using other diffusion methods.
          if (molarMass_g_Per_mol < 1000) {
            // Compute the vascular to extracellular permeability coefficient
            // This is the coefficient per gram of tissue independent of the tissue type.
            // This uses the Renkin and Curry data for capillary exchange as reported in \cite fournier2011basic
            // Divide by 100 is because the Renkin-Curry equations are in per hectogram units, and 100 g/hg
            /// \todo I believe we can optimize with a cache of these values. Also, we can cache permeabilityCoefficient_mL_Per_s_g which is not a function of the tissue properties
            double molecularRadius_nm = 0.0348 * pow(molarMass_g_Per_mol, 0.4175);
            double vToECpermeabilityCoefficient_mL_Per_s_g = 0.0287 * pow(molecularRadius_nm, -2.920) / 100.0; // This is only valid if the molecular radius is > 1.0 nm.
            if (molecularRadius_nm < 1.0)
              vToECpermeabilityCoefficient_mL_Per_s_g = 0.0184 * pow(molecularRadius_nm, -1.223) / 100.0;

            // Multiply by tissue mass to get the tissue-dependent coefficient.
            double vToECpermeabilityCoefficient_mL_Per_s = vToECpermeabilityCoefficient_mL_Per_s_g * tissue->GetTotalMass(MassUnit::g);

            // Tuning factors can be used to help tune the dynamics - note that concentrations will ALWAYS equilibrate in steady state given enough time regardless of the permeability
            double vToECPermeabilityTuningFactor = 1.0;
            double ECtoICPermeabilityTuningFactor = 1.0;

            //Vascular to Extracellular
            moved_ug = MoveMassBySimpleDiffusion(*vascular, extracellular, *sub, vToECPermeabilityTuningFactor * vToECpermeabilityCoefficient_mL_Per_s, m_Dt_s);

            //Extracellular to Intracellular
            // Assuming that the capillary permeability coefficient is proportional to the cellular membrane permeability coefficient for a given tissue and substance
            //Don't this is if substance is an ion, since extra<->intra has already been taken care of for them.  All of the ions have
            //a molar mass < 1000 so they will all funnel here
            if (sub->GetClassification() != CDM::enumSubstanceClass::Ion)
              moved_ug = MoveMassBySimpleDiffusion(extracellular, intracellular, *sub, ECtoICPermeabilityTuningFactor * vToECpermeabilityCoefficient_mL_Per_s, m_Dt_s);
          }

          //Facilitated diffusion depends on the substance having flux values
          //Currently, glucose is the only substance with "real" flux values (but even they are chosen to give good engine behavior)
          //TAG and ketones have "fake" flux values meant to give extra diffusion movement due to lipophilicity
          if (sub->HasMaximumDiffusionFlux()) {
            double massToAreaCoefficient_cm2_Per_g = 1.0; /// \todo Define relationship between tissue mass and membrane area.
            double capCoverage_cm2 = massToAreaCoefficient_cm2_Per_g * tissue->GetTotalMass(MassUnit::g);
            double maximumMassFlux = sub->GetMaximumDiffusionFlux(MassPerAreaTimeUnit::g_Per_cm2_s);
            double combinedCoefficient_g_Per_s = maximumMassFlux * capCoverage_cm2;

            //Vascular to Extracellular
            moved_ug = MoveMassByFacilitatedDiffusion(*vascular, extracellular, *sub, combinedCoefficient_g_Per_s, m_Dt_s);

            //Extracellular to Intracellular
            moved_ug = MoveMassByFacilitatedDiffusion(extracellular, intracellular, *sub, combinedCoefficient_g_Per_s, m_Dt_s);
          }
          //This Albumin diffusion is in case we start dynamically adjusting oncotic pressures, perhaps during hemorrhages or sepsis
          //  if (sub->GetName() == "Albumin" && tissue->GetReflectionCoefficient().GetValue()!=1.0)
          //  {
          //    //We don't transport albumin if the membrane is impermeable to albumin (i.e. reflection coefficient = 1).  This will cause undefined behavior
          //    double albuminK_mL_Per_s = 0.02;
          //    double vascularToExtraFlow_mL_Per_s = m_InterstitialCopPaths[tissue]->GetFlow(VolumePerTimeUnit::mL_Per_s);  //Vascular to Extra Path is first path in Tissue Paths vector
          //    double pecletNumber = abs(vascularToExtraFlow_mL_Per_s) * (1 - tissue->GetReflectionCoefficient().GetValue()) / albuminK_mL_Per_s;
          //    double num = vascular->GetSubstanceQuantity(*sub)->GetConcentration(MassPerVolumeUnit::ug_Per_mL)
          //      - exp(-pecletNumber) * extracellular.GetSubstanceQuantity(*sub)->GetConcentration(MassPerVolumeUnit::ug_Per_mL);
          //    double den = 1.0 - exp(-pecletNumber);
          //    moved_ug = vascularToExtraFlow_mL_Per_s * (1 - tissue->GetReflectionCoefficient().GetValue()) * (num / den) * m_Dt_s;
          //    if (moved_ug > 0)
          //    {
          //      if (moved_ug > vascular->GetSubstanceQuantity(*sub)->GetMass(MassUnit::ug))
          //      {
          //        moved_ug = vascular->GetSubstanceQuantity(*sub)->GetMass(MassUnit::ug);
          //      }
          //      DistributeMassbyVolumeWeighted(extracellular, *sub, moved_ug, MassUnit::ug);
          //      DistributeMassbyMassWeighted(*vascular, *sub, -moved_ug, MassUnit::ug);
          //    }
          //    else
          //    {
          //      if (-moved_ug > extracellular.GetSubstanceQuantity(*sub)->GetMass(MassUnit::ug))
          //      {
          //        moved_ug = -extracellular.GetSubstanceQuantity(*sub)->GetMass(MassUnit::ug);
          //      }
          //      DistributeMassbyMassWeighted(extracellular, *sub, moved_ug, MassUnit::ug);
          //      DistributeMassbyVolumeWeighted(*vascular, *sub, -moved_ug, MassUnit::ug);
          //    }
          //
          //  }
        }

        //Now that mass has been moved, balance to set concentrations and molarities
        vascular->GetSubstanceQuantity(*sub)->Balance(BalanceLiquidBy::Mass);
        extracellular.GetSubstanceQuantity(*sub)->Balance(BalanceLiquidBy::Mass);
        intracellular.GetSubstanceQuantity(*sub)->Balance(BalanceLiquidBy::Mass);
      }
    }
  }
}