Real
calc_median_sorting_variable(const Vector& sorting_variable,
			     const Vector& planck,
			     int i1, int i2) {
  Real half_planck = 0.5 * sum(planck(range(i1,i2)));
  Real cum_planck = 0.0;
  int iind = i1;
  for ( ; iind < i2; ++iind) {
    cum_planck += planck(iind);
    if (cum_planck >= half_planck) {
      break;
    }
  }
  return sorting_variable(iind);
}