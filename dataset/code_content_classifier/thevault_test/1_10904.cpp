TEST_F(StringRendererTest, DoesKeepAllImageBoxes) {
  renderer_ = std::make_unique<StringRenderer>("Verdana 10", 600, 600);
  Image pix = nullptr;
  int num_boxes_per_page = 0;
  const int kNumTrials = 2;
  for (int i = 0; i < kNumTrials; ++i) {
    EXPECT_EQ(strlen(kEngText), renderer_->RenderToImage(kEngText, strlen(kEngText), &pix));
    EXPECT_TRUE(pix != nullptr);
    pix.destroy();
    EXPECT_GT(renderer_->GetBoxes().size(), 0);
    if (!num_boxes_per_page) {
      num_boxes_per_page = renderer_->GetBoxes().size();
    } else {
      EXPECT_EQ((i + 1) * num_boxes_per_page, renderer_->GetBoxes().size());
    }
    for (int j = i * num_boxes_per_page; j < (i + 1) * num_boxes_per_page; ++j) {
      EXPECT_EQ(i, renderer_->GetBoxes()[j]->page());
    }
  }
}