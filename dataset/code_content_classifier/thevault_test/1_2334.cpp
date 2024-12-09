TEST_F(MultiSessionHitTestTest, ChildBiggerThanParent) {
  // Create our tokens for View/ViewHolder creation.
  auto [view_token, view_holder_token] = scenic::ViewTokenPair::New();
  auto [view_token2, view_holder_token2] = scenic::ViewTokenPair::New();

  CustomSession sess = CreateRootSession(1024, 768);
  {
    const uint32_t kViewHolderId = 35;
    sess.Apply(
        scenic::NewCreateViewHolderCmd(kViewHolderId, std::move(view_holder_token), "ViewHolder"));

    // Add the first view holder under the scene root, and the second view holder as a child of the
    // first view holder.
    sess.Apply(scenic::NewAddChildCmd(kSceneId, kViewHolderId));

    // Set view_holder 1's bounding box. It is a small box centered in the display.
    const float width = 100, height = 100;
    const float bbox_min[3] = {(layer_width() - width) / 2, (layer_height() - height) / 2, -6};
    const float bbox_max[3] = {(layer_width() + width) / 2, (layer_height() + height) / 2, -4};
    const float inset_min[3] = {0, 0, 0};
    const float inset_max[3] = {0, 0, 0};
    sess.Apply(
        scenic::NewSetViewPropertiesCmd(kViewHolderId, bbox_min, bbox_max, inset_min, inset_max));
  }

  // Sets up the parent view.
  CustomSession sess1 = CreateSession(2);
  {
    const uint32_t kViewId = 15;
    const uint32_t kMiddleNodeId = 37;
    const uint32_t kViewHolderId2 = 36;
    sess1.Apply(scenic::NewCreateViewCmd(kViewId, std::move(view_token), "MyView"));
    sess1.Apply(scenic::NewCreateEntityNodeCmd(kMiddleNodeId));
    sess1.Apply(scenic::NewAddChildCmd(kViewId, kMiddleNodeId));
    sess1.Apply(scenic::NewCreateViewHolderCmd(kViewHolderId2, std::move(view_holder_token2),
                                               "ViewHolder2"));
    sess1.Apply(scenic::NewAddChildCmd(kMiddleNodeId, kViewHolderId2));

    // Set view holder 2's bounding box. It takes up the entire display and thus is bigger
    // than it's parent's box.
    const float bbox_min2[3] = {0, 0, -9};
    const float bbox_max2[3] = {layer_width(), layer_height(), 0};
    const float inset_min[3] = {0, 0, 0};
    const float inset_max[3] = {0, 0, 0};
    sess1.Apply(scenic::NewSetViewPropertiesCmd(kViewHolderId2, bbox_min2, bbox_max2, inset_min,
                                                inset_max));
  }

  // Set up the child view.
  const uint32_t kInnerShapeNodeId = 50;
  CustomSession sess2 = CreateSession(3);
  {
    const uint32_t kViewId2 = 16;
    const uint32_t kOuterShapeNodeId = 51;
    const uint32_t kRectId = 70;

    const int32_t pane_width = 25;
    const int32_t pane_height = 25;

    sess2.Apply(scenic::NewCreateViewCmd(kViewId2, std::move(view_token2), "MyView2"));

    // Create shape node, apply rectangle and translate it outside the parent view.
    sess2.Apply(scenic::NewCreateShapeNodeCmd(kOuterShapeNodeId));
    sess2.Apply(scenic::NewCreateRectangleCmd(kRectId, pane_width, pane_height));
    sess2.Apply(scenic::NewSetShapeCmd(kOuterShapeNodeId, kRectId));
    sess2.Apply(scenic::NewSetTranslationCmd(
        kOuterShapeNodeId, (float[3]){layer_width() / 2, layer_height() / 2, -8.f}));
    sess2.Apply(scenic::NewAddChildCmd(kViewId2, kOuterShapeNodeId));

    // Create shape node, apply rectangle and translate it inside the parent view.
    sess2.Apply(scenic::NewCreateShapeNodeCmd(kInnerShapeNodeId));
    sess2.Apply(scenic::NewSetShapeCmd(kInnerShapeNodeId, kRectId));
    sess2.Apply(scenic::NewSetTranslationCmd(
        kInnerShapeNodeId, (float[3]){layer_width() / 2, layer_height() / 2, -5.f}));
    sess2.Apply(scenic::NewAddChildCmd(kViewId2, kInnerShapeNodeId));
  }

  {
    TestHitAccumulator<NodeHit> accumulator;
    HitTest(scene(), WorldSpaceCreateScreenPerpendicularRay(layer_width() / 2, layer_height() / 2),
            &accumulator);
    EXPECT_EQ(accumulator.hits().size(), 1u)
        << "Should only hit the shape encompassed by both views.";
    EXPECT_EQ(accumulator.hits().front().node->id(), kInnerShapeNodeId);
  }
}