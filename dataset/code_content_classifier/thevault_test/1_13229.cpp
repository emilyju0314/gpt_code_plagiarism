TEST_F(ViewManagerTest, CantGetNodeTreeOfOtherRoots) {
  // Create 1 and 2 in the first connection and parent both to the root.
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 1)));
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 2)));

  ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 1)));
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(0, 1), BuildNodeId(1, 2)));

  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(false));

  std::vector<TestNode> nodes;

  // Should get nothing for the root.
  connection2_->GetNodeTree(BuildNodeId(0, 1), &nodes);
  ASSERT_TRUE(nodes.empty());

  // Should get nothing for node 2.
  connection2_->GetNodeTree(BuildNodeId(1, 2), &nodes);
  ASSERT_TRUE(nodes.empty());

  // Should get node 1 if asked for.
  connection2_->GetNodeTree(BuildNodeId(1, 1), &nodes);
  ASSERT_EQ(1u, nodes.size());
  EXPECT_EQ("node=1,1 parent=null", nodes[0].ToString());
}