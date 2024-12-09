TEST_F(AnimGraphReferenceNodeWithAssetTests, VerifyRootTransform)
    {
        Evaluate();

        EXPECT_EQ(GetOutputTransform(), Transform::CreateIdentity());
    }