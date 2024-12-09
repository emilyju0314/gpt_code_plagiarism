Tabular_CP_Eloss::Tabular_CP_Eloss(std::string filename_in, rtt_cdi::CParticle target_in,
                                   rtt_cdi::CParticle projectile_in,
                                   rtt_cdi::CPModelAngleCutoff model_angle_cutoff_in)
    : rtt_cdi::CPEloss(target_in, projectile_in, rtt_cdi::CPModelType::TABULAR_ETYPE,
                       model_angle_cutoff_in),
      filename(std::move(filename_in)) {
  using std::stod;
  using std::stoi;

  file.open(filename);
  Insist(file.is_open(), "Error opening DEDX file \"" + filename + "\"");

  constexpr uint32_t max_entries =
      6; // This is a statement about the file format, maximum of six entries
         // per row

  std::vector<std::string> line_entries = read_line(); // ZAID
  int32_t projectile_zaid_file = stoi(line_entries[0]);
  Insist(projectile.get_zaid() == projectile_zaid_file,
         "File projectile ZAID does not match constructor argument!");

  skip_lines(1); // Z, A, mass

  line_entries = read_line(); // Number of bins for energy, density, temperature
  Check(line_entries.size() >= 3);
  n_energy = stoi(line_entries[0]);
  n_density = stoi(line_entries[1]);
  n_temperature = stoi(line_entries[2]);

  line_entries = read_line(); // Bin spacing for energy, density, temperature (log)
  Check(line_entries.size() >= 3);
  d_log_energy = stod(line_entries[0]);
  d_log_density = stod(line_entries[1]);
  d_log_temperature = stod(line_entries[2]);
  Require(d_log_energy > 0);
  Require(d_log_density > 0);
  Require(d_log_temperature > 0);
  d_log_energy = 1. / d_log_energy;
  d_log_density = 1. / d_log_density;
  d_log_temperature = 1. / d_log_temperature;

  // Get first energy support point
  uint32_t nlines = (n_energy + max_entries - 1) / max_entries;
  line_entries = read_line();
  min_log_energy = stod(line_entries[0]);
  skip_lines(nlines - 1);
  energies.resize(n_energy);
  for (uint32_t n = 0; n < n_energy; n++) {
    energies[n] = exp(min_log_energy + n * d_log_energy);
  }

  // Get first density support point
  nlines = (n_density + max_entries - 1) / max_entries;
  line_entries = read_line();
  min_log_density = stod(line_entries[0]);
  skip_lines(nlines - 1);
  densities.resize(n_density);
  for (uint32_t n = 0; n < n_density; n++) {
    densities[n] = exp(min_log_density + n * d_log_density);
  }

  // Get first temperature support point
  nlines = (n_temperature + max_entries - 1) / max_entries;
  line_entries = read_line();
  min_log_temperature = stod(line_entries[0]);
  skip_lines(nlines - 1);
  temperatures.resize(n_temperature);
  for (uint32_t n = 0; n < n_temperature; n++) {
    temperatures[n] = exp(min_log_temperature + n * d_log_temperature);
  }

  stopping_data_1d.resize(n_energy * n_density * n_temperature);

  bool target_found = false;
  nlines = (n_energy * n_density * n_temperature + max_entries - 1) /
           max_entries; // The number of lines taken up by stopping power data for
                        // one target
  if (target.get_zaid() == -1) {
    // Target is free electrons
    target_found = true;
    uint32_t nentry = 0;
    for (uint32_t n = 0; n < nlines; n++) {
      line_entries = read_line();
      for (std::string entry : line_entries) {
        stopping_data_1d[nentry++] = stod(entry);
      }
    }
  } else {
    // Skip electrons
    skip_lines(nlines);

    // Find ion target, if it exists
    const uint32_t n_target_ions = stoi(read_line()[0]); // Number of target ions in file
    for (uint32_t n_target_ion = 0; n_target_ion < n_target_ions; n_target_ion++) {
      int zaid_target_ion = stoi(read_line()[0]); // ZAID
      read_line();                                // Z, A, mass
      if (zaid_target_ion == target.get_zaid()) {
        // This is the requested target ion
        target_found = true;
        uint32_t nentry = 0;
        for (uint32_t n = 0; n < nlines; n++) {
          line_entries = read_line();
          for (std::string entry : line_entries) {
            stopping_data_1d[nentry] = stod(entry);
            nentry++;
          }
        }
        break;
      } else {
        // This is not the requested target ion
        skip_lines(nlines);
      }
    }
  }
  file.close();

  Insist(target_found, "Error finding target ZAID \"" + std::to_string(target.get_zaid()) +
                           "\" in DEDX file \"" + filename + "\"");

  stopping_data =
      basic_mdspan<double, extents<dynamic_extent, dynamic_extent, dynamic_extent>, layout_left>(
          stopping_data_1d.data(), n_energy, n_density, n_temperature);

  // Convert units on table to match those of getEloss:
  //   energy:      MeV -> cm/shk (using target particle mass)
  double energy_cgs = exp(min_log_energy) * (1.e6 * pc.electronVolt());
  min_log_energy = log(sqrt(2. * energy_cgs / target.get_mass()) * 1.e-8);
  d_log_energy = d_log_energy / 2.;
  //   density:     cm^-3 -> g cm^-3
  min_log_density = log(exp(min_log_density) * target.get_mass());
  //   temperature: keV -> keV
  // Note that d log x = dx / x is not affected by unit conversion factors
  for (auto &energy : energies) {
    energy = sqrt(2. * (energy * 1.e6 * pc.electronVolt()) / target.get_mass()) * 1.e-8;
  }
  for (auto &density : densities) {
    density *= target.get_mass();
  }

  // Initialize table bounds
  min_energy = exp(min_log_energy);
  max_energy = exp(min_log_energy + d_log_energy * (n_energy));
  min_density = exp(min_log_density);
  max_density = exp(min_log_density + d_log_density * (n_density));
  min_temperature = exp(min_log_temperature);
  max_temperature = exp(min_log_temperature + d_log_temperature * (n_temperature));
}