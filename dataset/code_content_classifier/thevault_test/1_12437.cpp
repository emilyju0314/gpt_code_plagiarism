TEST_F(BlendTreeTransformNodeTests, EvalauteTranslationBlending)
    {
        MCore::AttributeFloat* translate_amount = m_animGraphInstance->GetParameterValueChecked<MCore::AttributeFloat>(0);

        translate_amount->SetValue(0.0f);
        Evaluate();
        Transform outputRoot = GetOutputTransform();
        Transform expected = Transform::CreateIdentity();
        ASSERT_EQ(expected, outputRoot);

        translate_amount->SetValue(0.5f);
        Evaluate();
        expected.m_position = AZ::Vector3(5.0f, 0.0f, 0.0f);
        outputRoot = GetOutputTransform();
        ASSERT_EQ(expected, outputRoot);

        translate_amount->SetValue(1.0f);
        Evaluate();
        expected.m_position = AZ::Vector3(10.0f, 0.0f, 0.0f);
        outputRoot = GetOutputTransform();
        ASSERT_EQ(expected, outputRoot);
    }