bool Parse_Table::Keyword_Compare_::operator()(Keyword const &k1, Token const &k2) const noexcept {
  Require(k1.moniker != nullptr);

  return kt_comparison(k1.moniker, k2.text().c_str()) < 0;
}