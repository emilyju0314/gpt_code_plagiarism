TEST_F(MultiSessionHitTestTest, ChildCompletelyClipped) {
  // Create our tokens for View/ViewHolder creation.
  auto [view_token, view_holder_token] = scenic::ViewTokenPair::New();
  auto [view_token2, view_holder_token2] = scenic::ViewTokenPair::New();

  // Root session sets up the scene and two view holders.
  CustomSession sess = CreateRootSession(1024, 768);
  {
    const uint32_t kRootNodeId = 20007;
    const uint32_t kViewHolderId = 35;

    // Create root node and middle node.
    sess.Apply(scenic::NewCreateEntityNodeCmd(kRootNodeId));

    sess.Apply(
        scenic::NewCreateViewHolderCmd(kViewHolderId, std::move(view_holder_token), "ViewHolder"));

    // Add the first view holder as a child of the root node, and the second
    // view holder as a child of the first view holder.
    sess.Apply(scenic::NewAddChildCmd(kSceneId, kRootNodeId));
    sess.Apply(scenic::NewAddChildCmd(kRootNodeId, kViewHolderId));

    // Set view_holder 1's bounding box. It takes up the left-hand side of the display.
    const float bbox_min[3] = {0, 0, -9};
    const float bbox_max[3] = {layer_width() / 2, layer_height() / 2, 0};
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

    // Set view holder 2's bounding box. It takes up the right-hand side of the display.
    const float bbox_min2[3] = {layer_width() / 2, layer_height() / 2, -9};
    const float bbox_max2[3] = {layer_width(), layer_height(), 0};
    const float inset_min[3] = {0, 0, 0};
    const float inset_max[3] = {0, 0, 0};
    sess1.Apply(scenic::NewSetViewPropertiesCmd(kViewHolderId2, bbox_min2, bbox_max2, inset_min,
                                                inset_max));
  }

  // Set up the child view.
  CustomSession sess2 = CreateSession(3);
  {
    const uint32_t kViewId2 = 16;
    const uint32_t kShapeNodeId = 50;
    const uint32_t kRectId = 70;

    const int32_t pane_width = 25;
    const int32_t pane_height = 25;
    sess2.Apply(scenic::NewCreateViewCmd(kViewId2, std::move(view_token2), "MyView2"));

    // Create shape node and apply rectangle
    sess2.Apply(scenic::NewCreateShapeNodeCmd(kShapeNodeId));
    sess2.Apply(scenic::NewCreateRectangleCmd(kRectId, pane_width, pane_height));
    sess2.Apply(scenic::NewSetShapeCmd(kShapeNodeId, kRectId));
    sess2.Apply(scenic::NewSetTranslationCmd(
        kShapeNodeId, (float[3]){3.f * layer_width() / 4.f, 3.f * layer_height() / 4.f, -5.f}));
    sess2.Apply(scenic::NewAddChildCmd(kViewId2, kShapeNodeId));
  }

  {
    TestHitAccumulator<ViewHit> accumulator;
    layer_stack()->HitTest(
        input::CreateScreenPerpendicularRay(3 * layer_width() / 4, 3 * layer_height() / 4),
        &accumulator);
    EXPECT_TRUE(accumulator.hits().empty());
  }
}