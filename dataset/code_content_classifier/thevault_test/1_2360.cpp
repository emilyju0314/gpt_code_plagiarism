inline bool is_compatible(Unit const &a, Unit const &b) {
  return rtt_dsxx::soft_equiv(a.m, b.m) && rtt_dsxx::soft_equiv(a.kg, b.kg) &&
         rtt_dsxx::soft_equiv(a.s, b.s) && rtt_dsxx::soft_equiv(a.A, b.A) &&
         rtt_dsxx::soft_equiv(a.K, b.K) && rtt_dsxx::soft_equiv(a.mol, b.mol) &&
         rtt_dsxx::soft_equiv(a.cd, b.cd) && rtt_dsxx::soft_equiv(a.rad, b.rad) &&
         rtt_dsxx::soft_equiv(a.sr, b.sr);
}