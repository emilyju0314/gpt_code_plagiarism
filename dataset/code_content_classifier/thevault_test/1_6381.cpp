BOOST_AUTO_TEST_CASE(example_from_oases_mouse_chr1_cc_0_reverse_complemented)
{
  const char *seq = "CTAAGTTGCTTTTTCNTGACACCCCCAACTTACACATAAATTTAGTTATGTTTCTCATTGCTTTGCCCCTCCCCCCCCCATAACCTAGGTATACGAGGACATACCGGAGACCCCTAACACACACCCAGACAAGTAACTGTTAT";
  size_t k = 76;
  size_t len = strlen(seq);
  const char *end = seq + len + 1 - k;
  size_t after_N = 0;
  for (size_t i = 0; i < len; ++i) {
    if (seq[i] == 'N') {
      after_N = i + 1;
      break;
    }
  }
  // Check, assuming that we're at the beginning (each time).
  for (size_t i = 0; i + k - 1 < len; ++i) {
    if (i <= after_N)
      BOOST_CHECK_EQUAL(skip_Ns(seq + i, end, k, true), seq + after_N);
    else
      BOOST_CHECK_EQUAL(skip_Ns(seq + i, end, k, true), seq + i);
  }
  // Check, assuming that we are not at the beginning (each time).
  for (size_t i = 0; i + k - 1 < len; ++i)
    BOOST_CHECK_EQUAL(skip_Ns(seq + i, end, k, false), seq + i);
}