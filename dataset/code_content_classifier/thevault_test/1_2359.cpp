inline Unit pow(Unit const &b, double const a) {
  Unit result = b;
  result.m *= a;
  result.kg *= a;
  result.s *= a;
  result.A *= a;
  result.K *= a;
  result.mol *= a;
  result.cd *= a;
  result.rad *= a;
  result.sr *= a;
  result.conv = std::pow(b.conv, a);

  return result;
}