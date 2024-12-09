TEST_F(MultiSessionHitTestTest, GlobalHits) {
  // Create our tokens for View/ViewHolder creation.
  auto [view_token_1, view_holder_token_1] = scenic::ViewTokenPair::New();
  auto [view_token_2, view_holder_token_2] = scenic::ViewTokenPair::New();

  // Create bounds for the views.
  const float bbox_min[3] = {0, 0, -4};
  const float bbox_max[3] = {10, 10, 0};
  const float inset_min[3] = {0, 0, 0};
  const float inset_max[3] = {0, 0, 0};

  // Root session sets up the scene with two view holders and some geometry.
  CustomSession s_r = CreateRootSession(9, 9);
  {
    const uint32_t kRootNodeId = 1007;
    s_r.Apply(scenic::NewCreateEntityNodeCmd(kRootNodeId));

    const uint32_t kViewHolder1Id = 1008;
    s_r.Apply(scenic::NewAddChildCmd(kSceneId, kRootNodeId));
    s_r.Apply(scenic::NewCreateViewHolderCmd(kViewHolder1Id, std::move(view_holder_token_1),
                                             "viewholder_1"));
    s_r.Apply(scenic::NewAddChildCmd(kRootNodeId, kViewHolder1Id));

    const uint32_t kViewHolder2Id = 1009;
    s_r.Apply(scenic::NewCreateViewHolderCmd(kViewHolder2Id, std::move(view_holder_token_2),
                                             "viewholder_2"));
    s_r.Apply(scenic::NewAddChildCmd(kRootNodeId, kViewHolder2Id));

    s_r.Apply(
        scenic::NewSetViewPropertiesCmd(kViewHolder1Id, bbox_min, bbox_max, inset_min, inset_max));

    s_r.Apply(
        scenic::NewSetViewPropertiesCmd(kViewHolder2Id, bbox_min, bbox_max, inset_min, inset_max));

    const uint32_t kShapeNodeId = 1001;
    s_r.Apply(scenic::NewCreateShapeNodeCmd(kShapeNodeId));
    s_r.Apply(scenic::NewAddChildCmd(kRootNodeId, kShapeNodeId));
    s_r.Apply(scenic::NewSetTranslationCmd(kShapeNodeId, (float[3]){4.f, 4.f, /*z*/ -1.f}));

    const uint32_t kShapeId = 2004;
    s_r.Apply(scenic::NewCreateRectangleCmd(kShapeId, /*px-width*/ 9.f,
                                            /*px-height*/ 9.f));
    s_r.Apply(scenic::NewSetShapeCmd(kShapeNodeId, kShapeId));
  }

  // Two sessions (s_1 and s_2) create an overlapping and hittable surface.
  const uint32_t kViewId1 = 2001;
  CustomSession s_1(2, engine()->session_context());
  {
    s_1.Apply(scenic::NewCreateViewCmd(kViewId1, std::move(view_token_1), "view_1"));

    const uint32_t kRootNodeId = 2002;
    s_1.Apply(scenic::NewCreateEntityNodeCmd(kRootNodeId));
    s_1.Apply(scenic::NewAddChildCmd(kViewId1, kRootNodeId));

    const uint32_t kShapeNodeId = 2003;
    s_1.Apply(scenic::NewCreateShapeNodeCmd(kShapeNodeId));
    s_1.Apply(scenic::NewAddChildCmd(kRootNodeId, kShapeNodeId));
    s_1.Apply(scenic::NewSetTranslationCmd(kShapeNodeId, (float[3]){4.f, 4.f, /*z*/ -2.f}));

    const uint32_t kShapeId = 2004;  // Hit
    s_1.Apply(scenic::NewCreateRectangleCmd(kShapeId, /*px-width*/ 9.f,
                                            /*px-height*/ 9.f));
    s_1.Apply(scenic::NewSetShapeCmd(kShapeNodeId, kShapeId));
  }

  const uint32_t kViewId2 = 3001;
  CustomSession s_2(3, engine()->session_context());
  {
    s_2.Apply(scenic::NewCreateViewCmd(kViewId2, std::move(view_token_2), "view_2"));

    const uint32_t kRootNodeId = 3002;
    s_2.Apply(scenic::NewCreateEntityNodeCmd(kRootNodeId));
    s_2.Apply(scenic::NewAddChildCmd(kViewId2, kRootNodeId));

    const uint32_t kShapeNodeId = 3003;
    s_2.Apply(scenic::NewCreateShapeNodeCmd(kShapeNodeId));
    s_2.Apply(scenic::NewAddChildCmd(kRootNodeId, kShapeNodeId));
    s_2.Apply(scenic::NewSetTranslationCmd(kShapeNodeId, (float[3]){4.f, 4.f, /*z*/ -3.f}));

    const uint32_t kShapeId = 3004;  // Hit
    s_2.Apply(scenic::NewCreateRectangleCmd(kShapeId, /*px-width*/ 9.f,
                                            /*px-height*/ 9.f));
    s_2.Apply(scenic::NewSetShapeCmd(kShapeNodeId, kShapeId));
  }

  {
    SessionHitAccumulator accumulator;
    layer_stack()->HitTest(input::CreateScreenPerpendicularRay(4, 4), &accumulator);

    const auto& hits = accumulator.hits();

    // All that for this!
    ASSERT_EQ(hits.size(), 2u) << "Should see two hits across two view sessions.";
    EXPECT_EQ(hits[0].view->id(), kViewId2);
    EXPECT_EQ(hits[1].view->id(), kViewId1);
  }
}