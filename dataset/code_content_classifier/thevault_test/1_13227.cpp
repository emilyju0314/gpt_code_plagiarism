TEST_F(ViewManagerTest, ReuseDeletedNodeId) {
  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 2)));

  // Add 2 to 1.
  {
    ASSERT_TRUE(connection2_->AddNode(BuildNodeId(1, 1), BuildNodeId(2, 2)));

    connection_->DoRunLoopUntilChangesCount(1);
    const Changes changes(ChangesToDescription1(connection_->changes()));
    EXPECT_EQ("HierarchyChanged node=2,2 new_parent=1,1 old_parent=null",
              changes[0]);
    EXPECT_EQ("[node=2,2 parent=1,1]",
              ChangeNodeDescription(connection_->changes()));
  }

  // Delete 2.
  {
    ASSERT_TRUE(connection2_->DeleteNode(BuildNodeId(2, 2)));

    connection_->DoRunLoopUntilChangesCount(1);
    const Changes changes(ChangesToDescription1(connection_->changes()));
    ASSERT_EQ(1u, changes.size());
    EXPECT_EQ("NodeDeleted node=2,2", changes[0]);
  }

  // Create 2 again, and add it back to 1. Should get the same notification.
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 2)));
  {
    ASSERT_TRUE(connection2_->AddNode(BuildNodeId(1, 1), BuildNodeId(2, 2)));

    connection_->DoRunLoopUntilChangesCount(1);
    const Changes changes(ChangesToDescription1(connection_->changes()));
    EXPECT_EQ("HierarchyChanged node=2,2 new_parent=1,1 old_parent=null",
              changes[0]);
    EXPECT_EQ("[node=2,2 parent=1,1]",
              ChangeNodeDescription(connection_->changes()));
  }
}