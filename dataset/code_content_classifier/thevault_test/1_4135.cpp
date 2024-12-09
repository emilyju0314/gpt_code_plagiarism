tuple<uint,uint,uint> lrs(sequence<uchar> const &s) {
  timer t("lrs", true);

  sequence<uint> sa = suffix_array<uint>(s);
  t.next("suffix array");

  sequence<uint> lcps = lcp(s, sa);
  t.next("lcps");

  size_t idx = max_element(lcps, std::less<uint>());
  t.next("max element");
    
  return tuple<uint,uint,uint>(lcps[idx],sa[idx],sa[idx+1]);
}