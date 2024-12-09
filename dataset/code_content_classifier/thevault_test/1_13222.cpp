TEST_F(ViewManagerTest, NodesRemovedWhenEmbedding) {
  // Two nodes 1 and 2. 2 is parented to 1.
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 1)));
  ASSERT_TRUE(connection_->CreateNode(BuildNodeId(1, 2)));
  ASSERT_TRUE(connection_->AddNode(BuildNodeId(1, 1), BuildNodeId(1, 2)));

  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(false));
  EXPECT_EQ("[node=1,1 parent=null]",
            ChangeNodeDescription(connection2_->changes()));

  // Embed() removed node 2.
  {
    std::vector<TestNode> nodes;
    connection_->GetNodeTree(BuildNodeId(1, 2), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=1,2 parent=null", nodes[0].ToString());
  }

  // |connection2_| should not see node 2.
  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(1, 1), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=1,1 parent=null", nodes[0].ToString());
  }
  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(1, 2), &nodes);
    EXPECT_TRUE(nodes.empty());
  }

  // Nodes 3 and 4 in connection 2.
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 3)));
  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 4)));
  ASSERT_TRUE(connection2_->AddNode(BuildNodeId(2, 3), BuildNodeId(2, 4)));

  // Connection 3 rooted at 2.
  ASSERT_NO_FATAL_FAILURE(EstablishThirdConnection(connection2_,
                                                   BuildNodeId(2, 3)));

  // Node 4 should no longer have a parent.
  {
    std::vector<TestNode> nodes;
    connection2_->GetNodeTree(BuildNodeId(2, 3), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=2,3 parent=null", nodes[0].ToString());

    nodes.clear();
    connection2_->GetNodeTree(BuildNodeId(2, 4), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=2,4 parent=null", nodes[0].ToString());
  }

  // And node 4 should not be visible to connection 3.
  {
    std::vector<TestNode> nodes;
    connection3_->GetNodeTree(BuildNodeId(2, 3), &nodes);
    ASSERT_EQ(1u, nodes.size());
    EXPECT_EQ("node=2,3 parent=null", nodes[0].ToString());
  }
}