TEST_F(AnimGraphReferenceNodeBaseTests, VerifyRootTransform)
    {
        Evaluate();

        EXPECT_EQ(GetOutputTransform(), Transform::CreateIdentity());
    }