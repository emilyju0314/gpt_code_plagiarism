int Fl_Valuator::format(char* buffer) {
  double v = value();
  // MRS: THIS IS A HACK - RECOMMEND ADDING BUFFER SIZE ARGUMENT
  if (!A || !B) return snprintf(buffer, 128, "%g", v);

  // Figure out how many digits are required to correctly format the
  // value.
  int i, c = 0;
  char temp[32];
  // output a number with many digits after the decimal point. This
  // seems to be needed to get high precission
  snprintf(temp, sizeof(temp), "%.12f", A/B);
  // strip all trailing 0's
  for (i=strlen(temp)-1; i>0; i--) {
    if (temp[i]!='0') break;
  }
  // count digits until we find the decimal point (or comma or whatever
  // letter is set in the current locale)
  for (; i>0; i--, c++) {
    if (!isdigit(temp[i])) break;
  }

  // MRS: THIS IS A HACK - RECOMMEND ADDING BUFFER SIZE ARGUMENT
  return snprintf(buffer, 128, "%.*f", c, v);
}