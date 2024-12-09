bool Parse_Table::Keyword_Compare_::operator()(Keyword const &k1, Keyword const &k2) const {
  Require(k1.moniker != nullptr);
  Require(k2.moniker != nullptr);

  return kk_comparison(k1.moniker, k2.moniker) < 0;
}