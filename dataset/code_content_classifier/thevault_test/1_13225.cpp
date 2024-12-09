TEST_F(ViewManagerTest, AddToRoot) {
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 21)));
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 3)));

  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));

  // Make 3 a child of 21.
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 21), BuildNodeId(1, 3)));

  // Make 21 a child of 1.
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 1), BuildNodeId(1, 21)));

  // Connection 2 should not be told anything (because the node is from a
  // different connection). Create a node to ensure we got a response from
  // the server.
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 100)));
  connection2_->CopyChangesFromTracker();
  EXPECT_TRUE(connection2_->changes().empty());
}