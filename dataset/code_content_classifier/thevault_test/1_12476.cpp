TEST_F(GraphModelIntegrationTests, NodeWithDataSlotHasProperDataType)
    {
        // Create our test node
        GraphModel::NodePtr testNode = AZStd::make_shared<TestNode>(m_graph, m_graphContext);
        EXPECT_TRUE(testNode != nullptr);

        // Add our test node to the scene
        AZ::Vector2 offset;
        GraphCanvas::NodeId nodeId;
        GraphModelIntegration::GraphControllerRequestBus::EventResult(nodeId, m_sceneId, &GraphModelIntegration::GraphControllerRequests::AddNode, testNode, offset);

        // Retrieve the data type (string) for the string input slot on our test node
        GraphModel::SlotPtr testNodeStringInputSlot = testNode->GetSlot(TEST_STRING_INPUT_ID);
        EXPECT_TRUE(testNodeStringInputSlot != nullptr);
        GraphModel::DataTypePtr stringDataType = testNodeStringInputSlot->GetDataType();
        AZ::Uuid stringDataTypeId = stringDataType->GetTypeUuid();

        // Make sure our node has the expected slots
        AZStd::vector<AZ::EntityId> slotIds;
        GraphCanvas::NodeRequestBus::EventResult(slotIds, nodeId, &GraphCanvas::NodeRequests::GetSlotIds);
        EXPECT_EQ(slotIds.size(), 4);

        // Make sure the data type of the input string slot on our test node matches the expected data type
        AZ::EntityId slotId = slotIds[0];
        AZ::Uuid slotDataTypeId;
        GraphCanvas::DataSlotRequestBus::EventResult(slotDataTypeId, slotId, &GraphCanvas::DataSlotRequests::GetDataTypeId);
        EXPECT_EQ(stringDataTypeId, slotDataTypeId);
    }