int strcasecompare(const char *first, const char *second)
{
  while(*first && *second) {
    if(raw_toupper(*first) != raw_toupper(*second))
      /* get out of the loop as soon as they don't match */
      break;
    first++;
    second++;
  }
  /* we do the comparison here (possibly again), just to make sure that if the
     loop above is skipped because one of the strings reached zero, we must not
     return this as a successful match */
  return (raw_toupper(*first) == raw_toupper(*second));
}