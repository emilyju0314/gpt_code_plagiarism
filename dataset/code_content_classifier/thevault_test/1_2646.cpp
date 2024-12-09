Vector fit_optical_depth_sw_total_trans(
			    int i1, int i2,
			    const Vector& ssi,
			    const Matrix& bg_od, const Matrix& od) {
  int nz = od.size(0);
  Vector optical_depth_fit(nz);
  Vector flux_dn; flux_dn = ssi(range(i1,i2));
  Vector bg_flux_dn; bg_flux_dn = flux_dn;
  Real bb_flux_dn_top, bb_flux_dn_base;
  Real bb_bg_flux_dn_top, bb_bg_flux_dn_base;

  bb_flux_dn_top = bb_bg_flux_dn_top = sum(flux_dn);

  Real norm_factor = 1.0 / sum(ssi(range(i1,i2)));
  Real bg_od_fit;

  for (int iz = 0; iz < nz; ++iz) {
    // Factor of 2.0 is because we consider a 60 degree solar zenith angle
    bg_flux_dn *= exp(-2.0 * bg_od(iz,range(i1,i2)));
    flux_dn *= exp(-2.0 * (bg_od(iz,range(i1,i2))+od(iz,range(i1,i2))));
    bb_bg_flux_dn_base = sum(bg_flux_dn);
    bb_flux_dn_base = sum(flux_dn);
    if (bb_bg_flux_dn_base > 0.0 && bb_flux_dn_base > 0.0) {
      bg_od_fit = -0.5*log(bb_bg_flux_dn_base / bb_bg_flux_dn_top);
      optical_depth_fit(iz) = -0.5*log(bb_flux_dn_base / bb_flux_dn_top) - bg_od_fit;
    }
    else {
      optical_depth_fit = sum(od(__,range(i1,i2)) * spread<0>(ssi(range(i1,i2)),nz),1) * norm_factor;
    }
    bb_flux_dn_top = bb_flux_dn_base;
    bb_bg_flux_dn_top = bb_bg_flux_dn_base;
  }
  return optical_depth_fit;
}