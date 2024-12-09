bool RadarGroundMap::GetXY(const SurfacePoint &spoint, double *cudx,
                             double *cudy, bool test) {

    // Get the ground point in rectangular body-fixed coordinates (X)
    double X[3];
    X[0] = spoint.GetX().kilometers();
    X[1] = spoint.GetY().kilometers();
    X[2] = spoint.GetZ().kilometers();

    // Compute body-fixed look vector
    SpiceRotation *bodyFrame = p_camera->bodyRotation();
    SpicePosition *spaceCraft = p_camera->instrumentPosition();

    std::vector<double> sJ(6);   // Spacecraft state vector (position and velocity) in J2000 frame
    // Load the state into sJ
    vequ_c((SpiceDouble *) & (spaceCraft->Coordinate()[0]), &sJ[0]);
    vequ_c((SpiceDouble *) & (spaceCraft->Velocity()[0]), &sJ[3]);

    // Rotate the state to body-fixed
    p_sB.resize(6);
    p_sB = bodyFrame->ReferenceVector(sJ);

    // Extract the body-fixed position and velocity
    SpiceDouble VsB[3];
    SpiceDouble PsB[3];
    vequ_c(&p_sB[0], PsB);
    vequ_c(&p_sB[3], VsB);

    p_lookB.resize(3);
    vsub_c(X, PsB, &p_lookB[0]);

    p_groundSlantRange = vnorm_c(&p_lookB[0]);  // km
    p_groundDopplerFreq = 2. / p_waveLength / p_groundSlantRange * vdot_c(&p_lookB[0], &VsB[0]);
    *cudx = p_groundSlantRange * 1000.0 / p_rangeSigma;  // to meters, then to focal plane coord
    *cudy = p_groundDopplerFreq / p_dopplerSigma;   // htx to focal plane coord

    if (test == true) {
      QString msg = "Back of planet test is not enabled for Radar images";
       throw IException(IException::Programmer, msg, _FILEINFO_);
    }

    return true;
  }