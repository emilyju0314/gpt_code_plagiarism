void check_equal_both_ways(size_t seg1_start_a, size_t seg1_end_a, size_t seg1_start_b, size_t seg1_end_b,
                           size_t seg2_start_a, size_t seg2_end_a, size_t seg2_start_b, size_t seg2_end_b,
                           bool does_intersect,
                           size_t tru1_start_a, size_t tru1_end_a, size_t tru1_start_b, size_t tru1_end_b,
                           size_t tru2_start_a, size_t tru2_end_a, size_t tru2_start_b, size_t tru2_end_b)
{
  {
    VAS segs1 { {seg1_start_a, seg1_end_a, seg1_start_b, seg1_end_b, {}, {}} };
    VAS segs2 { {seg2_start_a, seg2_end_a, seg2_start_b, seg2_end_b, {}, {}} };
    BOOST_CHECK_EQUAL(intersects<segment_ops_wrt_b>(segs1, segs2), does_intersect);

    VAS pred = subtract<segment_ops_wrt_b>(segs2, segs1);
    VAS trut { {tru1_start_a, tru1_end_a, tru1_start_b, tru1_end_b, {}, {}},
               {tru2_start_a, tru2_end_a, tru2_start_b, tru2_end_b, {}, {}} };
    BOOST_CHECK_EQUAL(pred, trut);
  }

  {
    VAS segs1 { {seg1_start_b, seg1_end_b, seg1_start_a, seg1_end_a, {}, {}} };
    VAS segs2 { {seg2_start_b, seg2_end_b, seg2_start_a, seg2_end_a, {}, {}} };
    BOOST_CHECK_EQUAL(intersects<segment_ops_wrt_a>(segs1, segs2), does_intersect);

    VAS pred = subtract<segment_ops_wrt_a>(segs2, segs1);
    VAS trut { {tru1_start_b, tru1_end_b, tru1_start_a, tru1_end_a, {}, {}},
               {tru2_start_b, tru2_end_b, tru2_start_a, tru2_end_a, {}, {}} };
    BOOST_CHECK_EQUAL(pred, trut);
  }
}