TEST_F(EmotionFXMathLibTests, AZQuaternionConversion_ToMatrix_Success)
{
    AZ::Vector3 axis = AZ::Vector3(1.0f, 0.7f, 0.3f);
    axis.Normalize();
    AZ::Quaternion azQuaternion = AZ::Quaternion::CreateFromAxisAngle(axis, AZ::Constants::HalfPi);

    AZ::Matrix4x4 azMatrix = AZ::Matrix4x4::CreateFromQuaternion(azQuaternion);
    AZ::Transform azTransform = AZ::Transform::CreateFromQuaternionAndTranslation(azQuaternion, AZ::Vector3::CreateZero());

    bool same = true;

    AZ::Vector3 azTransformBasis[4];
    azTransform.GetBasisAndTranslation(&azTransformBasis[0], &azTransformBasis[1], &azTransformBasis[2], &azTransformBasis[3]);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            float emValue = azTransformBasis[j].GetElement(i);
            float azValue = azMatrix.GetElement(i, j);
            if (!AZ::IsClose(emValue, azValue, s_toleranceReallyLow))
            {
                same = false;
                break;
            }
        }

        if (!same)
        {
            break;
        }
    }
    ASSERT_TRUE(same);
    ASSERT_TRUE(AZ::IsClose(azMatrix.GetElement(3, 0), 0.0f, s_toleranceReallyLow));
    ASSERT_TRUE(AZ::IsClose(azMatrix.GetElement(3, 1), 0.0f, s_toleranceReallyLow));
    ASSERT_TRUE(AZ::IsClose(azMatrix.GetElement(3, 2), 0.0f, s_toleranceReallyLow));
    ASSERT_TRUE(AZ::IsClose(azMatrix.GetElement(3, 3), 1.0f, s_toleranceReallyLow));
}