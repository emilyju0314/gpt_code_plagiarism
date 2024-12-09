void check_empty_both_ways(size_t seg1_start_a, size_t seg1_end_a, size_t seg1_start_b, size_t seg1_end_b,
                           size_t seg2_start_a, size_t seg2_end_a, size_t seg2_start_b, size_t seg2_end_b)
{
  {
    VAS segs1 { {seg1_start_a, seg1_end_a, seg1_start_b, seg1_end_b, {}, {}} };
    VAS segs2 { {seg2_start_a, seg2_end_a, seg2_start_b, seg2_end_b, {}, {}} };
    BOOST_CHECK(intersects<segment_ops_wrt_b>(segs1, segs2));

    VAS pred = subtract<segment_ops_wrt_b>(segs2, segs1);
    VAS trut {};
    BOOST_CHECK_EQUAL(pred, trut);
  }

  {
    VAS segs1 { {seg1_start_b, seg1_end_b, seg1_start_a, seg1_end_a, {}, {}} };
    VAS segs2 { {seg2_start_b, seg2_end_b, seg2_start_a, seg2_end_a, {}, {}} };
    BOOST_CHECK(intersects<segment_ops_wrt_a>(segs1, segs2));

    VAS pred = subtract<segment_ops_wrt_a>(segs2, segs1);
    VAS trut {};
    BOOST_CHECK_EQUAL(pred, trut);
  }
}