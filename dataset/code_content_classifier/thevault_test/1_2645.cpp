Vector fit_optical_depth_sw(const std::string& averaging_method,
			    int i1, int i2,
			    const Vector& ssi,
			    const Matrix& metric) {
  Vector optical_depth_fit;
  int nz = metric.size(0);
  Real norm_factor = 1.0 / sum(ssi(range(i1,i2)));
  if (averaging_method == "linear") {
    optical_depth_fit = sum(metric(__,range(i1,i2)) * spread<0>(ssi(range(i1,i2)),nz),1) * norm_factor;
  }
  else if (averaging_method == "transmission") {
    optical_depth_fit = min(0.9999999999999999,sum(metric(__,range(i1,i2)) * spread<0>(ssi(range(i1,i2)),nz),1))
      * norm_factor;
    optical_depth_fit = abs(-log(1.0-optical_depth_fit)/LW_DIFFUSIVITY);
  }
  else if (averaging_method == "transmission-2") {
    optical_depth_fit = min(0.9999999999999999,sum(metric(__,range(i1,i2)) * spread<0>(ssi(range(i1,i2)),nz),1))
      * norm_factor;
    optical_depth_fit = abs(-log(1.0-optical_depth_fit)/(LW_DIFFUSIVITY*2.0));
  }
  else if (averaging_method == "square-root") {
    optical_depth_fit = sum(metric(__,range(i1,i2)) * spread<0>(ssi(range(i1,i2)),nz),1)
      * norm_factor;
    optical_depth_fit *= optical_depth_fit;
  }
  else if (averaging_method == "logarithmic"
	   || averaging_method == "total-transmission") {
    optical_depth_fit.resize(nz);
    for (int iz = 0; iz < nz; ++iz) {
      intVector iindex = i1+find(metric(iz,range(i1,i2)) > 0.0);
      Vector od_nonzero = metric(iz,iindex);
      if (od_nonzero.size() == i2-i1+1) {
	// Pure logarithmic average
	optical_depth_fit(iz) = exp(sum(log(od_nonzero)*ssi(iindex))
				    / sum(ssi(iindex)));
      }
      else if (od_nonzero.empty()) {
	// No non-zero data
	optical_depth_fit(iz) = 0.0;
      }
      else {
	// Some zeros: logarithmic average of non-zeros then linear average with zeros
	optical_depth_fit(iz) = exp(sum(log(od_nonzero)*ssi(iindex))
				    / sum(ssi(iindex)))
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