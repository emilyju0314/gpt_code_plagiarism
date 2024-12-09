TEST_F(ViewManagerTest, CantAccessChildrenOfEmbeddedNode) {
  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));

  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 2)));
  ASSERT_TRUE(connection2_->AddNode(BuildNodeId(1, 1), BuildNodeId(2, 2)));

  ASSERT_NO_FATAL_FAILURE(EstablishThirdConnection(connection2_,
                                                   BuildNodeId(2, 2)));

  ASSERT_TRUE(connection3_->CreateNode(BuildNodeId(3, 3)));
  ASSERT_TRUE(connection3_->AddNode(BuildNodeId(2, 2), BuildNodeId(3, 3)));

  // Even though 3 is a child of 2 connection 2 can't see 3 as it's from a
  // different connection.
  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(2, 2), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=2,2 parent=1,1", nodes[0].ToString());
  }

  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(3, 3), &nodes);
    EXPECT_TRUE(nodes.empty());
  }

  // Connection 2 shouldn't be able to get node 3 at all.
  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(3, 3), &nodes);
    EXPECT_TRUE(nodes.empty());
  }

  // Connection 1 should be able to see it all (its the root).
  {
    std::vector<TestNode> nodes;
    connection_->GetNodeTree(BuildNodeId(1, 1), &nodes);
    ASSERT_EQ(3u, nodes.size());
    EXPECT_EQ("node=1,1 parent=null", nodes[0].ToString());
    EXPECT_EQ("node=2,2 parent=1,1", nodes[1].ToString());
    EXPECT_EQ("node=3,3 parent=2,2", nodes[2].ToString());
  }
}