TEST_F(ResultIteratorTest, DualStartTextlineOrderTest) {
  const StrongScriptDirection word_dirs[] = {dL, dL, dN, dL, dN, dR, dR, dR};
  int reading_order_rtl_context[] = {7, 6, 5, 4, ResultIterator::kMinorRunStart,
                                     0, 1, 2, 3, ResultIterator::kMinorRunEnd};
  int reading_order_ltr_context[] = {
      0, 1, 2, 3, 4, ResultIterator::kMinorRunStart, 7, 6, 5, ResultIterator::kMinorRunEnd};

  ExpectTextlineReadingOrder(true, word_dirs, countof(word_dirs), reading_order_ltr_context,
                             countof(reading_order_ltr_context));
  ExpectTextlineReadingOrder(false, word_dirs, countof(word_dirs), reading_order_rtl_context,
                             countof(reading_order_rtl_context));
}