Vector fit_optical_depth_lw(const std::string& averaging_method,
			    int i1, int i2,
			    const Matrix& planck_hl,
			    const Matrix& metric) {
  Vector optical_depth_fit;

  if (averaging_method == "linear") {
    optical_depth_fit = sum(metric(__,range(i1,i2)) * planck_hl(range(1,end),range(i1,i2)), 1)
      / sum(planck_hl(range(1,end),range(i1,i2)),1);
  }
  else if (averaging_method == "transmission") {
    optical_depth_fit = min(0.9999999999999999,sum(metric(__,range(i1,i2)) * planck_hl(range(1,end),range(i1,i2)), 1)
			    / sum(planck_hl(range(1,end),range(i1,i2)),1));
    optical_depth_fit = abs(-log(1.0-optical_depth_fit)/LW_DIFFUSIVITY);
  }
  else if (averaging_method == "transmission-2") {
    optical_depth_fit = min(0.9999999999999999,sum(metric(__,range(i1,i2)) * planck_hl(range(1,end),range(i1,i2)), 1)
			    / sum(planck_hl(range(1,end),range(i1,i2)),1));
    optical_depth_fit = abs(-log(1.0-optical_depth_fit)/(LW_DIFFUSIVITY*2.0));
  }
  else if (averaging_method == "square-root") {
    optical_depth_fit = sum(metric(__,range(i1,i2)) * planck_hl(range(1,end),range(i1,i2)), 1)
      / sum(planck_hl(range(1,end),range(i1,i2)),1);
    optical_depth_fit *= optical_depth_fit;
  }
  else if (averaging_method == "logarithmic") {
    optical_depth_fit.resize(metric.size(0));
    for (int iz = 0; iz < metric.size(0); ++iz) {
      intVector iindex = i1+find(metric(iz,range(i1,i2)) > 0.0);
      Vector od_nonzero = metric(iz,iindex);
      if (od_nonzero.size() == i2-i1+1) {
	// Pure logarithmic average
	optical_depth_fit(iz) = exp(sum(log(od_nonzero)*planck_hl(iz+1,iindex))
				    / sum(planck_hl(iz,iindex)));
      }
      else if (od_nonzero.empty()) {
	// No non-zero data
	optical_depth_fit(iz) = 0.0;
      }
      else {
	// Some zeros: logarithmic average of non-zeros then linear average with zeros
	optical_depth_fit(iz) = exp(sum(log(od_nonzero)*planck_hl(iz+1,iindex))
				    / sum(planck_hl(iz,iindex)))
	  * (static_cast<Real>(iindex.size())/static_cast<Real>(i2-i1+1));
      }
    }
  }
  else {
    ERROR << "Averaging method \"" << averaging_method << "\" not understood";
    THROW(PARAMETER_ERROR);
  }
  return optical_depth_fit;
}