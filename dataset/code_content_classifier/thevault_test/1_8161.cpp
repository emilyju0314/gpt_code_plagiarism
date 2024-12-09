bool ConsumeDurationNumber(const wchar_t **dpp, const wchar_t *ep, int64_t *int_part, int64_t *frac_part,
                           int64_t *frac_scale) {
  *int_part = 0;
  *frac_part = 0;
  *frac_scale = 1; // invariant: *frac_part < *frac_scale
  const wchar_t *start = *dpp;
  for (; *dpp != ep; *dpp += 1) {
    const int d = **dpp - '0'; // contiguous digits
    if (d < 0 || 10 <= d) {
      break;
    }

    if (*int_part > kint64max / 10) {
      return false;
    }
    *int_part *= 10;
    if (*int_part > kint64max - d) {
      return false;
    }
    *int_part += d;
  }
  const bool int_part_empty = (*dpp == start);
  if (*dpp == ep || **dpp != '.') {
    return !int_part_empty;
  }

  for (*dpp += 1; *dpp != ep; *dpp += 1) {
    const int d = **dpp - '0'; // contiguous digits
    if (d < 0 || 10 <= d) {
      break;
    }
    if (*frac_scale <= kint64max / 10) {
      *frac_part *= 10;
      *frac_part += d;
      *frac_scale *= 10;
    }
  }
  return !int_part_empty || *frac_scale != 1;
}