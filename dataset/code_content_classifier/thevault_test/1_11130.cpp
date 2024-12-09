TEST_F(ResultIteratorTest, LeftwardTextlineOrderTest) {
  const StrongScriptDirection word_dirs[] = {dL, dL, dN, dL, dN, dN, dL, dL};
  // The order here is just left to right, nothing fancy.
  int reading_order_ltr_context[] = {0, 1, 2, 3, 4, 5, 6, 7};
  // In the strange event that this shows up in an RTL paragraph, nonetheless
  // just presume the whole thing is an LTR line.
  int reading_order_rtl_context[] = {ResultIterator::kMinorRunStart, 0, 1, 2, 3, 4, 5, 6, 7,
                                     ResultIterator::kMinorRunEnd};

  ExpectTextlineReadingOrder(true, word_dirs, countof(word_dirs), reading_order_ltr_context,
                             countof(reading_order_ltr_context));
  ExpectTextlineReadingOrder(false, word_dirs, countof(word_dirs), reading_order_rtl_context,
                             countof(reading_order_rtl_context));
}