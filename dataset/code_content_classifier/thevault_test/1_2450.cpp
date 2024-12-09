double IpcressDataTable::interpOpac(double const targetTemperature, double const targetDensity,
                                    size_t const group) const {
  double logT = std::log(targetTemperature);
  double logrho = std::log(targetDensity);

  size_t const numrho = logDensities.size();
  size_t const numT = logTemperatures.size();
  size_t const ng = opacityEnergyDescriptor == std::string("gray") ? 1 : groupBoundaries.size() - 1;

  // Check if we are off the table boundaries.  We don't allow extrapolation,
  // so move the target temperature or density to the table boundary.
  Check(numT > 1);
  Check(numrho > 1);
  if (targetTemperature < temperatures[0])
    logT = std::log(temperatures[0]);
  if (targetTemperature > temperatures[numT - 1])
    logT = std::log(temperatures[numT - 1]);
  if (targetDensity < densities[0])
    logrho = std::log(densities[0]);
  if (targetDensity > densities[numrho - 1])
    logrho = std::log(densities[numrho - 1]);

  /*
   * The grid looks like this:
   *
   *      |   T1     |   T      |   T2
   * -----------------------------------------
   * rho1 |   sig11  |          |   sig13
   * -----------------------------------------
   * rho  |   sig21  |  sig22   |   sig23
   * -----------------------------------------
   * rho2 |   sig31  |          |   sig33
   *
   * - rho1, rho2, T1 and T2 are table values.
   * - sig11, sig13, sig31 and sig33 are table values.
   *
   * Use linear interploation wrt log(rho) to find sig21 and sig23, then use
   * linear interpolation wrt log(T) to find sig22.
   */

  // Find the bracketing table values (T1, T2) and (rho1, rho2) for rho and T.
  size_t irho = logDensities.size() - 1;
  size_t iT = logTemperatures.size() - 1;
  for (size_t i = 0; i < numT - 1; ++i) {
    if (logT >= logTemperatures[i] && logT < logTemperatures[i + 1]) {
      iT = i;
      break;
    }
  }
  for (size_t i = 0; i < numrho - 1; ++i) {
    if (logrho >= logDensities[i] && logrho < logDensities[i + 1]) {
      irho = i;
      break;
    }
  }

  // Perform the linear interpolation.

  // index of cell with lower T and lower rho bound
  size_t i = (iT * numrho + irho) * ng + group;
  size_t k = i + ng * numrho; // index for cell with higher T value

  // If we are on the edge of the opacity table, return the edge values.  So
  // there are 4 cases:
  double logOpacity(0.0);

  // 1. Normal path
  if (irho + 1 < numrho && iT + 1 < numT) {
    double logsig12 = logOpacities[i] + (logrho - logDensities[irho]) /
                                            (logDensities[irho + 1] - logDensities[irho]) *
                                            (logOpacities[i + ng] - logOpacities[i]);

    double logsig32 = logOpacities[k] + (logrho - logDensities[irho]) /
                                            (logDensities[irho + 1] - logDensities[irho]) *
                                            (logOpacities[k + ng] - logOpacities[k]);

    logOpacity = logsig12 + (logT - logTemperatures[iT]) /
                                (logTemperatures[iT + 1] - logTemperatures[iT]) *
                                (logsig32 - logsig12);
  }

  // 2. rho is at high side of table, T is in the table
  else if (irho + 1 >= numrho && iT + 1 < numT) {
    logOpacity = logOpacities[i] + (logT - logTemperatures[iT]) /
                                       (logTemperatures[iT + 1] - logTemperatures[iT]) *
                                       (logOpacities[k] - logOpacities[i]);
  }

  // 3. T is at high side of table, rho is in the table
  else if (irho + 1 < numrho && iT + 1 >= numT) {
    logOpacity = logOpacities[i] + (logrho - logDensities[irho]) /
                                       (logDensities[irho + 1] - logDensities[irho]) *
                                       (logOpacities[i + ng] - logOpacities[i]);
  }

  // 4. Both T and rho are on the high side of the table.
  else if (irho + 1 >= numrho && iT + 1 >= numT) {
    logOpacity = logOpacities[i];
  }

  return std::exp(logOpacity);
}