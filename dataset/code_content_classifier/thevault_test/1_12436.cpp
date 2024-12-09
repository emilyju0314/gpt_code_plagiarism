TEST_F(BlendTreeTransformNodeTests, Evaluate)
    {
        Evaluate();
        ASSERT_EQ(Transform::CreateIdentity(), GetOutputTransform());
    }