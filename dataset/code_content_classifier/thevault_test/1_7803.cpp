bool EditDistance::similar(char const *s, char const *t, const int threshold)
{
  int lens = strlen(s);
  int lent = strlen(t);

  if (lens > lent && lens - lent > threshold)
    return false;

  if (lent > lens && lent - lens > threshold)
    return false;

  return (LD(s, t) <= threshold);
}