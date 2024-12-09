TEST_F(SceneGraphTest, GetNodeName_NodeExists_ReturnsCorrectName)
            {
                SceneGraph testSceneGraph;

                AZStd::string expectedNodeName("TestNode");

                testSceneGraph.AddChild(testSceneGraph.GetRoot(), expectedNodeName.c_str());
                SceneGraph::NodeIndex foundIndex = testSceneGraph.Find(expectedNodeName);
                ASSERT_TRUE(foundIndex.IsValid());
                const SceneGraph::Name& nodeName = testSceneGraph.GetNodeName(foundIndex);
                EXPECT_STREQ(expectedNodeName.c_str(), nodeName.GetPath());
                EXPECT_STREQ(expectedNodeName.c_str(), nodeName.GetName());
            }