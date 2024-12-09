py::array_t<double> no::MonteCarlo::next_arrival(const py::array_t<double>& startingpoints, const py::array_t<double>& lambda_t, double dt, bool relative, double minsep)
{
  validate_lambda(lambda_t);
  size_t n = startingpoints.size();

  const double* pl = no::cbegin(lambda_t);
  size_t nl = lambda_t.size();
  double tmax = (nl - 1) * dt;

  // What is the optimal lambda_u? For now largest value
  double lambda_u = *std::max_element(pl, pl + nl);
  double lambda_i;

  py::array_t<double> times(n);
  double* pt = no::begin(times);

  for (size_t i = 0; i < n; ++i)
  {
    // account for any deterministic time lag (e.g. 9 months between births)
    double offset = no::at(startingpoints, {static_cast<py::ssize_t>(i)}) + minsep;
    // skip if we haven't actually arrived at the state to transition from
    if (no::time::isnever(offset))
    {
      pt[i] = no::time::never();
      continue;
    }
    // offset if lambdas in absolute time (not relative to start point)
    pt[i] = relative ? 0.0 : offset;
    do
    {
      pt[i] += -::log(u01()) / lambda_u;
      // final entry in lambda_t is flat extrapolated...
      lambda_i = pl[ std::min((size_t)(pt[i] / dt), nl-1) ];
      if (pt[i] > tmax && lambda_i == 0.0)
      {
        pt[i] = no::time::never();
        break;
      }
    } while (u01() > lambda_i / lambda_u);
    // restore offset if required
    pt[i] += relative ? offset : 0.0;
  }
  return times;
}