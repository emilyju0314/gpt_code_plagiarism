adept::Real
calc_cost_function_lw(const adept::Vector& pressure_hl,       ///< Pressure (Pa)
		      const adept::Matrix& planck_hl,         ///< Planck function (W m-2)
		      const adept::Vector& surf_emissivity,   ///< Surface emissivity
		      const adept::Vector& surf_planck,       ///< Surface spectral Planck function (W m-2)
		      const adept::Matrix& bg_optical_depth,  ///< Background optical depth
		      const adept::Vector& optical_depth_fit, ///< Fitted optical depth of target gas
		      const adept::Vector& flux_dn_surf,      ///< True downwelling surface flux (W m-2)
		      const adept::Vector& flux_up_toa,       ///< True upwelling TOA flux (W m-2)
		      const adept::Matrix& hr,                ///< True heating rate (K s-1)
		      adept::Real flux_weight,                ///< Weight applied to TOA and surface fluxes
		      const adept::Vector& layer_weight,      ///< Weight applied to heating rates in each layer
		      const adept::intVector& index           ///< Indices of wavenumbers to consider
		      ) {
  using namespace adept;

  // Convert K s-1 to K day-1
  static const Real hr_weight = 3600.0*24.0;

  int nlay = pressure_hl.size()-1;
  int nwav = surf_planck.size();

  Vector hr_true;
  Real flux_dn_surf_true;
  Real flux_up_toa_true;

  if (index.empty()) {
    hr_true           = sum(hr,1);
    flux_dn_surf_true = sum(flux_dn_surf);
    flux_up_toa_true  = sum(flux_up_toa);
  }
  else {
    hr_true           = sum(hr(__,index),1);
    flux_dn_surf_true = sum(flux_dn_surf(index));
    flux_up_toa_true  = sum(flux_up_toa(index));
  }

#ifdef WASTE_MEMORY

  // I've no idea if this is still valid...

  Matrix flux_dn(nlay+1,nwav);
  Matrix flux_up(nlay+1,nwav);
  radiative_transfer_lw(planck_hl(__,index),
			eval(bg_optical_depth(__,index) + spread<1>(optical_depth_fit,nwav)),
			surf_emissivity(index),
			surf_planck(index),
			flux_dn,
			flux_up);

  Vector flux_dn_fit = sum(flux_dn,1);
  Vector flux_up_fit = sum(flux_up,1);

#else

  Vector flux_dn_fit(nlay+1);
  Vector flux_up_fit(nlay+1);
  if (index.empty()) {
    radiative_transfer_lw_bb(planck_hl,
			     bg_optical_depth,
			     optical_depth_fit,
			     surf_emissivity,
			     surf_planck,
			     flux_dn_fit,
			     flux_up_fit);
  }
  else {
    radiative_transfer_lw_bb(planck_hl(__,index),
			     eval(bg_optical_depth(__,index)),
			     optical_depth_fit,
			     surf_emissivity(index),
			     surf_planck(index),
			     flux_dn_fit,
			     flux_up_fit);
  }

#endif

  Vector hr_fit(nlay);
  heating_rate_single(pressure_hl, flux_dn_fit, flux_up_fit, hr_fit);

  //  std::cerr << "HRtrue = " << hr_true << "\n";
  //  std::cerr << "HRfit = " << hr_fit << "\n";

  return sqrt(hr_weight*hr_weight*sum(layer_weight*((hr_fit-hr_true)*(hr_fit-hr_true)))
	      + flux_weight*((flux_dn_fit(end)-flux_dn_surf_true)*(flux_dn_fit(end)-flux_dn_surf_true)
			     +(flux_up_fit(0)-flux_up_toa_true)*(flux_up_fit(0)-flux_up_toa_true)));
}