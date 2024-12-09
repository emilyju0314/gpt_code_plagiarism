TEST_F(ViewManagerTest, CantRemoveNodesInOtherRoots) {
  // Create 1 and 2 in the first connection and parent both to the root.
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 1)));
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 2)));

  ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 1)));
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 2)));

  // Establish the second connection and give it the root 1.
  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(false));

  // Connection 2 should not be able to remove node 2 or 1 from its parent.
  ASSERT_FALSE(connection2_->RemoveNodeFromParent(BuildNodeId(1, 2)));
  ASSERT_FALSE(connection2_->RemoveNodeFromParent(BuildNodeId(1, 1)));

  // Create nodes 10 and 11 in 2.
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 10)));
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 11)));

  // Parent 11 to 10.
  ASSERT_TRUE(connection2_->AddNode(BuildNodeId(2, 10), BuildNodeId(2, 11)));
  // Remove 11 from 10.
  ASSERT_TRUE(connection2_->RemoveNodeFromParent( BuildNodeId(2, 11)));

  // Verify nothing was actually removed.
  {
    std::vector<TestNode> nodes;
    connection_->GetNodeTree(BuildNodeId(0, 1), &nodes);
    ASSERT_EQ(3u, nodes.size());
    EXPECT_EQ("node=0,1 parent=null", nodes[0].ToString());
    EXPECT_EQ("node=1,1 parent=0,1", nodes[1].ToString());
    EXPECT_EQ("node=1,2 parent=0,1", nodes[2].ToString());
  }
}