bool RadarGroundMap::GetdXYdPosition(const SpicePosition::PartialType varType, int coefIndex,
                                       double *dx, double *dy) {
    SpicePosition *instPos = p_camera->instrumentPosition();
    SpiceRotation *bodyRot = p_camera->bodyRotation();

    std::vector <double> d_lookJ(6);
    vequ_c(&(instPos->CoordinatePartial(varType, coefIndex))[0], &d_lookJ[0]);
    vequ_c(&(instPos->VelocityPartial(varType, coefIndex))[0], &d_lookJ[3]);

    std::vector<double> d_lookB =  bodyRot->ReferenceVector(d_lookJ);

    double d_slantRange = (-1.) * vdot_c(&p_lookB[0], &d_lookB[0]) / p_groundSlantRange;
    double d_dopplerFreq = (-1.) * p_groundDopplerFreq * d_slantRange / p_groundSlantRange -
                           2. / p_waveLength / p_groundSlantRange * vdot_c(&d_lookB[0], &p_sB[3]) +
                           2. / p_waveLength / p_groundSlantRange * vdot_c(&p_lookB[0], &d_lookB[3]);

    *dx = d_slantRange * 1000.0 / p_rangeSigma;// km to meters, then to focal plane coord
    *dy = d_dopplerFreq / p_dopplerSigma;   // htz scaled to focal plane

    return true;
  }