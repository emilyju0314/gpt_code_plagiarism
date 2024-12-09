TEST_F(ViewManagerTest, CantModifyChildrenOfEmbeddedNode) {
  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));

  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 2)));
  ASSERT_TRUE(connection2_->AddNode(BuildNodeId(1, 1), BuildNodeId(2, 2)));

  ASSERT_NO_FATAL_FAILURE(EstablishThirdConnection(connection2_,
                                                   BuildNodeId(2, 2)));

  ASSERT_TRUE(connection2_->CreateNode(BuildNodeId(2, 3)));
  // Connection 2 shouldn't be able to add anything to the node anymore.
  ASSERT_FALSE(connection2_->AddNode(BuildNodeId(2, 2), BuildNodeId(2, 3)));

  // Create node 3 in connection 3 and add it to node 3.
  ASSERT_TRUE(connection3_->CreateNode(BuildNodeId(3, 3)));
  ASSERT_TRUE(connection3_->AddNode(BuildNodeId(2, 2), BuildNodeId(3, 3)));

  // Connection 2 shouldn't be able to remove node 3.
  ASSERT_FALSE(connection2_->RemoveNodeFromParent(BuildNodeId(3, 3)));
}