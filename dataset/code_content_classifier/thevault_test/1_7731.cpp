void  LocApiV02 :: reportSvPolynomial (
  const qmiLocEventGnssSvPolyIndMsgT_v02 *gnss_sv_poly_ptr)
{
  GnssSvPolynomial  svPolynomial;

  memset(&svPolynomial, 0, sizeof(GnssSvPolynomial));
  svPolynomial.size = sizeof(GnssSvPolynomial);
  svPolynomial.is_valid = 0;

  if(0 != gnss_sv_poly_ptr->gnssSvId)
  {
    svPolynomial.gnssSvId       = gnss_sv_poly_ptr->gnssSvId;
    svPolynomial.T0             = gnss_sv_poly_ptr->T0;

    if(1 == gnss_sv_poly_ptr->gloFrequency_valid)
    {
      svPolynomial.is_valid  |= ULP_GNSS_SV_POLY_BIT_GLO_FREQ;
      svPolynomial.freqNum   = gnss_sv_poly_ptr->gloFrequency;
    }
    if(1 == gnss_sv_poly_ptr->IODE_valid)
    {
      svPolynomial.is_valid  |= ULP_GNSS_SV_POLY_BIT_IODE;
      svPolynomial.iode       = gnss_sv_poly_ptr->IODE;
     }

    if(1 == gnss_sv_poly_ptr->svPosUnc_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_SV_POSUNC;
      svPolynomial.svPosUnc = gnss_sv_poly_ptr->svPosUnc;
    }

    if(0 != gnss_sv_poly_ptr->svPolyFlagValid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_FLAG;
      svPolynomial.svPolyStatusMaskValidity = gnss_sv_poly_ptr->svPolyFlagValid;
      svPolynomial.svPolyStatusMask = gnss_sv_poly_ptr->svPolyFlags;
    }

    if(1 == gnss_sv_poly_ptr->polyCoeffXYZ0_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_POLYCOEFF_XYZ0;
      for(int i=0;i<GNSS_SV_POLY_XYZ_0_TH_ORDER_COEFF_MAX_SIZE;i++)
      {
        svPolynomial.polyCoeffXYZ0[i] = gnss_sv_poly_ptr->polyCoeffXYZ0[i];
      }
    }

    if(1 == gnss_sv_poly_ptr->polyCoefXYZN_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_POLYCOEFF_XYZN;
      for(int i=0;i<GNSS_SV_POLY_XYZ_N_TH_ORDER_COEFF_MAX_SIZE;i++)
      {
        svPolynomial.polyCoefXYZN[i] = gnss_sv_poly_ptr->polyCoefXYZN[i];
      }
    }

    if(1 == gnss_sv_poly_ptr->polyCoefClockBias_valid)
    {

      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_POLYCOEFF_OTHER;
      for(int i=0;i<GNSS_SV_POLY_SV_CLKBIAS_COEFF_MAX_SIZE;i++)
      {
        svPolynomial.polyCoefOther[i] = gnss_sv_poly_ptr->polyCoefClockBias[i];
      }
    }

    if(1 == gnss_sv_poly_ptr->ionoDot_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_IONODOT;
      svPolynomial.ionoDot = gnss_sv_poly_ptr->ionoDot;
    }
    if(1 == gnss_sv_poly_ptr->ionoDelay_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_IONODELAY;
      svPolynomial.ionoDelay = gnss_sv_poly_ptr->ionoDelay;
    }

    if(1 == gnss_sv_poly_ptr->sbasIonoDot_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_SBAS_IONODOT;
      svPolynomial.sbasIonoDot = gnss_sv_poly_ptr->sbasIonoDot;
    }
    if(1 == gnss_sv_poly_ptr->sbasIonoDelay_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_SBAS_IONODELAY;
      svPolynomial.sbasIonoDelay = gnss_sv_poly_ptr->sbasIonoDelay;
    }
    if(1 == gnss_sv_poly_ptr->tropoDelay_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_TROPODELAY;
      svPolynomial.tropoDelay = gnss_sv_poly_ptr->tropoDelay;
    }
    if(1 == gnss_sv_poly_ptr->elevation_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_ELEVATION;
      svPolynomial.elevation = gnss_sv_poly_ptr->elevation;
    }
    if(1 == gnss_sv_poly_ptr->elevationDot_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_ELEVATIONDOT;
      svPolynomial.elevationDot = gnss_sv_poly_ptr->elevationDot;
    }
    if(1 == gnss_sv_poly_ptr->elenationUnc_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_ELEVATIONUNC;
      svPolynomial.elevationUnc = gnss_sv_poly_ptr->elenationUnc;
    }
    if(1 == gnss_sv_poly_ptr->velCoef_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_VELO_COEFF;
      for(int i=0;i<GNSS_SV_POLY_VELOCITY_COEF_MAX_SIZE;i++)
      {
        svPolynomial.velCoef[i] = gnss_sv_poly_ptr->velCoef[i];
      }
    }
    if(1 == gnss_sv_poly_ptr->enhancedIOD_valid)
    {
      svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_ENHANCED_IOD;
      svPolynomial.enhancedIOD = gnss_sv_poly_ptr->enhancedIOD;
    }

    if(1 == gnss_sv_poly_ptr->gpsIscL1ca_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GPS_ISC_L1CA;
        svPolynomial.gpsIscL1ca = gnss_sv_poly_ptr->gpsIscL1ca;
    }

    if(1 == gnss_sv_poly_ptr->gpsIscL2c_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GPS_ISC_L2C;
        svPolynomial.gpsIscL2c = gnss_sv_poly_ptr->gpsIscL2c;
    }

    if(1 == gnss_sv_poly_ptr->gpsIscL5I5_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GPS_ISC_L5I5;
        svPolynomial.gpsIscL5I5 = gnss_sv_poly_ptr->gpsIscL5I5;
    }

    if(1 == gnss_sv_poly_ptr->gpsIscL5Q5_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GPS_ISC_L5Q5;
        svPolynomial.gpsIscL5Q5 = gnss_sv_poly_ptr->gpsIscL5Q5;
    }

    if(1 == gnss_sv_poly_ptr->gpsTgd_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GPS_TGD;
        svPolynomial.gpsTgd = gnss_sv_poly_ptr->gpsTgd;
    }

    if(1 == gnss_sv_poly_ptr->gloTgdG1G2_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GLO_TGD_G1G2;
        svPolynomial.gloTgdG1G2 = gnss_sv_poly_ptr->gloTgdG1G2;
    }

    if(1 == gnss_sv_poly_ptr->bdsTgdB1_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_BDS_TGD_B1;
        svPolynomial.bdsTgdB1 = gnss_sv_poly_ptr->bdsTgdB1;
    }

    if(1 == gnss_sv_poly_ptr->bdsTgdB2_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_BDS_TGD_B2;
        svPolynomial.bdsTgdB2= gnss_sv_poly_ptr->bdsTgdB2;
    }

    if(1 == gnss_sv_poly_ptr->bdsTgdB2a_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_BDS_TGD_B2A;
        svPolynomial.bdsTgdB2a = gnss_sv_poly_ptr->bdsTgdB2a;
    }

    if(1 == gnss_sv_poly_ptr->bdsIscB2a_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_BDS_ISC_B2A;
        svPolynomial.bdsIscB2a = gnss_sv_poly_ptr->bdsIscB2a;
    }

    if(1 == gnss_sv_poly_ptr->galBgdE1E5a_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GAL_BGD_E1E5A;
        svPolynomial.galBgdE1E5a = gnss_sv_poly_ptr->galBgdE1E5a;
    }

    if(1 == gnss_sv_poly_ptr->galBgdE1E5b_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_GAL_BGD_E1E5B;
        svPolynomial.galBgdE1E5b = gnss_sv_poly_ptr->galBgdE1E5b;
    }

    if(1 == gnss_sv_poly_ptr->navicTgdL5_valid)
    {
        svPolynomial.is_valid |= ULP_GNSS_SV_POLY_BIT_NAVIC_TGD_L5;
        svPolynomial.navicTgdL5 = gnss_sv_poly_ptr->navicTgdL5;
    }

    LocApiBase::reportSvPolynomial(svPolynomial);

    LOC_LOGV("[SV_POLY_QMI] SV-Id:%d\n", svPolynomial.gnssSvId);
  }
  else
  {
     LOC_LOGV("[SV_POLY]  INVALID SV-Id:%d", svPolynomial.gnssSvId);
  }
}