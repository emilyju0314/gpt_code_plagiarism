BOOST_AUTO_TEST_CASE(example_from_oases_mouse_chr1_cc_0)
{
  const char *seq = "ATAACAGTTACTTGTCTGGGTGTGTGTTAGGGGTCTCCGGTATGTCCTCGTATACCTAGGTTATGGGGGGGGGAGGGGCAAAGCAATGAGAAACATAACTAAATTTATGTGTAAGTTGGGGGTGTCANGAAAAAGCAACTTAG";
  size_t k = 76;
  size_t len = strlen(seq);
  const char *end = seq + len + 1 - k;
  for (size_t i = 0; i + k - 1 < len; ++i) {
    if (seq[i + k - 1] != 'N')
      BOOST_CHECK_EQUAL(skip_Ns(seq + i, end, k, i == 0), seq + i);
    else
      BOOST_CHECK_EQUAL(skip_Ns(seq + i, end, k, i == 0), end);
  }
}