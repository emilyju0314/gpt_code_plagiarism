TEST_F(ViewManagerTest, NodeHierarchyChangedNodes) {
  // 1,2->1,11.
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 2)));
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 11)));
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 2), BuildNodeId(1, 11)));

  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));

  // 1,1->1,2->1,11
  {
    // Client 2 should not get anything (1,2 is from another connection).
    connection2_->ClearChanges();
    ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 1), BuildNodeId(1, 2)));
    ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 100)));
    connection2_->CopyChangesFromTracker();
    EXPECT_TRUE(connection2_->changes().empty());
  }

  // 0,1->1,1->1,2->1,11.
  {
    // Again, client 2 should not get anything.
    connection2_->ClearChanges();
    ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 1)));
    ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 101)));
    connection2_->CopyChangesFromTracker();
    EXPECT_TRUE(connection2_->changes().empty());
  }

  // 1,1->1,2->1,11.
  {
    connection2_->ClearChanges();
    ASSERT_TRUE(connection_->RemoveNodeFromParent(BuildNodeId(1, 1)));
    EXPECT_TRUE(connection_->changes().empty());
    ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 102)));
    connection2_->CopyChangesFromTracker();
    EXPECT_TRUE(connection2_->changes().empty());
  }

  // 1,1->1,2->1,11->1,111.
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 111)));
  {
    connection2_->ClearChanges();
    ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 11), BuildNodeId(1, 111)));
    ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 103)));
    connection2_->CopyChangesFromTracker();
    EXPECT_TRUE(connection2_->changes().empty());
  }

  // 0,1->1,1->1,2->1,11->1,111
  {
    connection2_->ClearChanges();
    ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 1)));
    ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 104)));
    connection2_->CopyChangesFromTracker();
    EXPECT_TRUE(connection2_->changes().empty());
  }
}