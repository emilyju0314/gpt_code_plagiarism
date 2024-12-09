void TextlineProjection::PlotGradedBlobs(BLOBNBOX_LIST *blobs, ScrollView *win) {
  BLOBNBOX_IT it(blobs);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    BLOBNBOX *blob = it.data();
    const TBOX &box = blob->bounding_box();
    bool bad_box = BoxOutOfHTextline(box, nullptr, false);
    if (blob->UniquelyVertical()) {
      win->Pen(ScrollView::YELLOW);
    } else {
      win->Pen(bad_box ? ScrollView::RED : ScrollView::BLUE);
    }
    win->Rectangle(box.left(), box.bottom(), box.right(), box.top());
  }
  win->Update();
}