bool ParallelUnitTest::check_all(bool const i_am_good, std::string const &passmsg,
                                 bool const fatal) {
  unsigned good = i_am_good;
  rtt_c4::global_min(good);
  unsigned p = rtt_c4::node();
  if (good) {
    if (p == 0)
      passes(passmsg);
  } else {
    int igood = i_am_good;
    std::vector<int> ps(rtt_c4::nodes());
    rtt_c4::gather(&igood, &ps[0], 1);
    if (p == 0) {
      failure(passmsg);
      out << "failing processors:";
      for (int i = 0; i < rtt_c4::nodes(); ++i) {
        if (!ps[i])
          out << ' ' << i;
      }
      out << std::endl;
    }
    if (fatal)
      throw rtt_dsxx::assertion("assertion thrown on critical check failure");
  }
  return true;
}