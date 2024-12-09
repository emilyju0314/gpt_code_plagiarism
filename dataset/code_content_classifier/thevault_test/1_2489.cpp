DummyGrayOpacity::DummyGrayOpacity(rtt_cdi::Reaction reaction, rtt_cdi::Model model)
    : dataFilename("none"), dataDescriptor("DummyGrayOpacity"), energyPolicyDescriptor("Gray"),
      temperatureGrid(), densityGrid(), reaction_type(reaction), model_type(model) {
  // Set up the temperature and density grid.
  temperatureGrid.resize(numTemperatures);
  densityGrid.resize(numDensities);
  for (size_t i = 0; i < numTemperatures; ++i)
    temperatureGrid[i] = static_cast<double>(i + 1);
  for (size_t i = 0; i < numDensities; ++i)
    densityGrid[i] = 0.1 * static_cast<double>(i + 1);
}