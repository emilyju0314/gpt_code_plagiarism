bool RadarGroundMap::Iterate(SpiceDouble &R, const double &slantRangeSqr, const SpiceDouble c[],
                               const SpiceDouble r[], SpiceDouble X[], SpiceDouble &lat,
                               SpiceDouble &lon, const std::vector<double> &Xsc,
                               const bool &useSlopeEqn, const double &slope) {

    lat = DBL_MAX;
    lon = DBL_MAX;
    SpiceDouble lastR = DBL_MAX;
    SpiceDouble rlat;
    SpiceDouble rlon;
    int iter = 0;
    do {
      double normXsc = vnorm_c(&Xsc[0]);
      double alpha = (R * R - slantRangeSqr - normXsc * normXsc) /
                     (2.0 * vdot_c(&Xsc[0], c));

      double arg = slantRangeSqr - alpha * alpha;
      if(arg < 0.0) return false;

      double beta = sqrt(arg);
      if(p_lookDirection == Radar::Left) beta *= -1.0;

      SpiceDouble alphac[3], betar[3];
      vscl_c(alpha, c, alphac);
      vscl_c(beta, r, betar);

      vadd_c(alphac, betar, alphac);
      vadd_c(&Xsc[0], alphac, X);

      // Convert X to lat,lon
      lastR = R;
      reclat_c(X, &R, &lon, &lat);

      rlat = lat * 180.0 / Isis::PI;
      rlon = lon * 180.0 / Isis::PI;
      if(useSlopeEqn) {
        R = lastR + slope * (p_camera->LocalRadius(rlat, rlon).kilometers() - lastR);
      } else {
        R = p_camera->LocalRadius(rlat, rlon).kilometers();
      }
      
      iter++;
    }
    while(fabs(R - lastR) > p_tolerance && iter < 100);

    if(fabs(R - lastR) > p_tolerance) return false;
 
    return true;
  }