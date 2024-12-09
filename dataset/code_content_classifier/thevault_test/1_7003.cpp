bool check_valid_ssn(string ssn) {
  int len = ssn.length();
  if (len != 9) {
    return false;
  }
  for (int i = 0; i < len; i++) {
    if (!isdigit(ssn[i])) {
      return false;
    }
  }
  return true;
}