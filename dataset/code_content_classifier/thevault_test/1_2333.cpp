TEST_F(SingleSessionHitTestTest, ViewClipping) {
  // Create our tokens for View/ViewHolder creation.
  auto [view_token, view_holder_token] = scenic::ViewTokenPair::New();

  CustomSession sess = CreateRootSession(1024, 768);
  {
    enum : uint32_t {
      kViewId = 15,
      kViewHolderId,
      kShapeNodeId,
      kRectId,
    };

    const int32_t pane_width = layer_width();
    const int32_t pane_height = 0.25 * layer_height();

    sess.Apply(scenic::NewCreateViewHolderCmd(kViewHolderId, std::move(view_holder_token),
                                              "MyViewHolder"));
    sess.Apply(scenic::NewCreateViewCmd(kViewId, std::move(view_token), "MyView"));

    // Set the bounding box on the view holder.
    const float bbox_min[3] = {0.f, 0.f, -2.f};
    const float bbox_max[3] = {layer_width() / 2, layer_height(), 1.f};
    const float inset_min[3] = {0, 0, 0};
    const float inset_max[3] = {0, 0, 0};
    sess.Apply(
        scenic::NewSetViewPropertiesCmd(kViewHolderId, bbox_min, bbox_max, inset_min, inset_max));

    // Create shape node and apply rectangle
    sess.Apply(scenic::NewCreateShapeNodeCmd(kShapeNodeId));
    sess.Apply(scenic::NewCreateRectangleCmd(kRectId, pane_width, pane_height));
    sess.Apply(scenic::NewSetShapeCmd(kShapeNodeId, kRectId));
    sess.Apply(scenic::NewSetTranslationCmd(
        kShapeNodeId, (float[3]){0.5f * pane_width, 0.5f * layer_height(), 0.f}));

    sess.Apply(scenic::NewAddChildCmd(kSceneId, kViewHolderId));
    sess.Apply(scenic::NewAddChildCmd(kViewId, kShapeNodeId));
  }

  // Perform two hit tests on either side of the display.
  {
    // First hit test should intersect the view's bounding box.
    TestHitAccumulator<ViewHit> accumulator;
    layer_stack()->HitTest(input::CreateScreenPerpendicularRay(5, layer_height() / 2),
                           &accumulator);
    EXPECT_EQ(accumulator.hits().size(), 1u) << "Should see a hit on the rectangle";
  }
  {
    // Second hit test should completely miss the view's bounding box.
    TestHitAccumulator<ViewHit> accumulator;
    layer_stack()->HitTest(
        input::CreateScreenPerpendicularRay(layer_width() / 2 + 50, layer_height() / 2),
        &accumulator);
    EXPECT_EQ(accumulator.hits().size(), 0u)
        << "Should see no hits since its outside the view bounds";
  }
}