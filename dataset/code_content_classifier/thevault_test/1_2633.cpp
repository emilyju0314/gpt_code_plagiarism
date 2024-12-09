void ep_print_result(EpStatus istatus, int iverbose,
		     int ni, ep_real* bounds, ep_real* error)
{
  ep_real mean_error, chi2;
  ep_real frac_std, frac_range;
  ep_stats(ni, &error[0], mean_error, chi2,
	   &frac_std, &frac_range);

  std::cout << "  Equipartition status: " << ep_status_string(istatus)
	    << "\n      fractional range = " << frac_range
	    << "\n      fractional standard deviation = " << frac_std
	    << std::endl;
  if (iverbose > 1) {
    print_bounds(ni, bounds);
    print_error(ni, error);
  }
}