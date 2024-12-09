void ROW::move(      // reposition row
    const ICOORD vec // by vector
) {
  WERD_IT it(&words); // word iterator

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    it.data()->move(vec);
  }

  bound_box.move(vec);
  baseline.move(vec);
}