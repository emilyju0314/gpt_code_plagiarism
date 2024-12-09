int
overlap_g_points(std::vector<SingleGasData>& gas_data,
		 intVector& band_number) {
  const int ngas  = gas_data.size();
  const int nband = gas_data[0].n_g_points.size();
  intVector ng_band(nband);

  for (int iband = 0; iband < nband; ++iband) {
    // Number of g points per band is given by Eq. 7 of Hogan (2010):
    // 1-ngas+\sum_i=1^ngas(ng_i)
    ng_band(iband) = 1-ngas;
    for (int igas = 0; igas < ngas; ++igas) {
      ng_band(iband) += gas_data[igas].n_g_points[iband];
    }
  }

  int ng = sum(ng_band); // Total number of g points

  band_number.resize(ng);
  {
    int ig = 0;
    for (int iband = 0; iband < nband; ++iband) {
      band_number(range(ig,ig+ng_band(iband)-1)) = iband;
      ig += ng_band(iband);
    }
  }

  for (int igas = 0; igas < ngas; ++igas) {
    gas_data[igas].g_min.resize(ng);
    gas_data[igas].g_max.resize(ng);
  }

  int ig = 0; // Index of current "total" g point
  intVector ig_gas(ngas); // Index of current g point for each
			  // individual gas
  ig_gas = 0.0;

  for (int iband = 0; iband < nband; ++iband) {
    LOG << "Band " << iband << "\n";
    intVector ig_gas_start;
    ig_gas_start = ig_gas;
    // First "total" g point in each band is the intersection of the
    // first g point for each of the individual gases
    LOG << "  G-point " << ig << ": intersection of weakest spectral interval of each gas\n";
    for (int igas = 0; igas < ngas; ++igas) {
      gas_data[igas].g_min(ig) = ig_gas_start(igas);
      gas_data[igas].g_max(ig) = ig_gas_start(igas);
    }

    // Loop over total g points for this band
    for (int ig_band = 1; ig_band < ng_band(iband); ++ig_band) {
      // Find minimum sorting variable amongst the gases
      Real min_sorting_var = 1.0e30;
      int i_found_gas = -1;
      for (int igas = 0; igas < ngas; ++igas) {
	Real my_sorting_var = 1.0e30;
	if (ig_gas(igas) < ig_gas_start(igas)+gas_data[igas].n_g_points[iband]-1) {
	  my_sorting_var = gas_data[igas].sorting_variable(ig_gas(igas)+1);
	}
	//	else {
	//	  LOG << "  Reached maximum for gas " << igas << "\n";
	//	}
	if (my_sorting_var < min_sorting_var) {
	  min_sorting_var = my_sorting_var;
	  i_found_gas = igas;
	}
      }
      if (i_found_gas < 0) {
	ERROR << "Could not locate next gas to advance";
	throw;
      }

      ++ig_gas(i_found_gas);

      ++ig;

      LOG << "  G-point " << ig << ": major gas " << gas_data[i_found_gas].Molecule
	  << " (" << ig_gas(i_found_gas) << ")\n";

      for (int igas = 0; igas < ngas; ++igas) {
	if (i_found_gas == igas) {
	  gas_data[igas].g_min(ig) = ig_gas(igas);
	  gas_data[igas].g_max(ig) = ig_gas(igas);
	}
	else {
	  gas_data[igas].g_min(ig) = ig_gas_start(igas);
	  gas_data[igas].g_max(ig) = ig_gas(igas);
  	}
      } 
    }

    // Need to make sure that the indices are incremented ready for
    // the first "intersection of weakest" merged-gpoint of the next
    // band
    ++ig;
    for (int igas = 0; igas < ngas; ++igas) {
      ++ig_gas(igas);
    }

  }
  return ng;
}