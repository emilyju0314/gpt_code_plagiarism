void ModelObThreshold::applyFilter(const std::vector<bool> & apply,
                                   const Variables & filtervars,
                                   std::vector<std::vector<bool>> & flagged) const {
  oops::Log::trace() << "ModelObThreshold priorFilter" << std::endl;
  print(oops::Log::trace());

  const float missing = util::missingValue(missing);
  const size_t nlocs = obsdb_.nlocs();

// Get piece-wise parameters from options.
  const std::vector<double> coord_vals = parameters_.coord_vals.value();
  const std::vector<double> thresholds = parameters_.thresholds.value();
  oops::Log::debug() << "QC coord vals are " << coord_vals << std::endl;
  oops::Log::debug() << "QC thresholds are " << thresholds << std::endl;

// get names of GeoVal variables
  const std::string model_profile_name = Variable(parameters_.model_profile).variable();
  const std::string model_vcoord_name = Variable(parameters_.model_vcoord).variable();

  std::ostringstream errString;
// Ensure same size vectors (coord_vals and threshold); Also ensure more than one value in each.
  if (coord_vals.size() <= 1 || coord_vals.size() != thresholds.size()) {
      errString << "At least one of coord_vals, thresholds is wrong size - either unequal or < 2"
                << oops::listOfVectorSizes(coord_vals, thresholds) << std::endl;
      throw eckit::BadValue(errString.str());
  }

// Get variables from ObsSpace
// Get obs_height, the observation height
  std::vector<float> obs_height;
  data_.get(parameters_.obs_height, obs_height);

// Get GeoVaLs
  const ufo::GeoVaLs * gvals = data_.getGeoVaLs();

// Setup interpolation of height-dependent thresholds
// N.B. inputs to interp must be double precision
  ufo::PiecewiseLinearInterpolation interp_thresholds(coord_vals, thresholds);

// Loop through locations
  for (size_t iloc=0; iloc < nlocs; ++iloc) {
    // interpolate threshold values to observation height
    float bg_threshold = interp_thresholds(obs_height[iloc]);

    // Vectors storing GeoVaL column for current location.
    std::vector <double> model_profile_column;
    std::vector <double> model_vcoord_column;
    model_profile_column.assign(gvals->nlevs(model_profile_name), 0.0);
    model_vcoord_column.assign(gvals->nlevs(model_vcoord_name), 0.0);
    // Get GeoVaLs at the specified location.
    gvals->getAtLocation(model_profile_column, model_profile_name, iloc);
    gvals->getAtLocation(model_vcoord_column, model_vcoord_name, iloc);

    // interpolate model profile values to observation height
    ufo::PiecewiseLinearInterpolation interp_model(model_vcoord_column, model_profile_column);
    float bg_model = interp_model(obs_height[iloc]);

    // Apply threshold
    if (apply[iloc]) {
      // check to see if one of the compared values is missing
      if (bg_model == missing || bg_threshold == missing) {
        for (size_t jv = 0; jv < filtervars.nvars(); ++jv) {
          flagged[jv][iloc] = true;
        }
      } else {
      // Check if model value is outside threshold and set flag
        for (size_t jv = 0; jv < filtervars.nvars(); ++jv) {
          if (parameters_.threshold_type == ThresholdType::MIN) {
            if (bg_model < (bg_threshold)) {
              flagged[jv][iloc] = true;
            }
          }
          if (parameters_.threshold_type == ThresholdType::MAX) {
            if (bg_model > (bg_threshold)) {
              flagged[jv][iloc] = true;
            }
          }
        }
      }
    }
  }
}