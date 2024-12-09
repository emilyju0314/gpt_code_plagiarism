TEST_F(EmotionFXMathLibTests, AZQuaternion_Rotation1ComponentAxisX_Success)
{
    AZ::Vector3 axis = AZ::Vector3(1.0f, 0.0f, 0.0f);
    axis.Normalize();
    AZ::Quaternion azQuaternion1 = AZ::Quaternion::CreateFromAxisAngle(axis, AZ::Constants::HalfPi);
    AZ::Vector3 vertexIn(0.0f, 0.0f, 0.1f);
    AZ::Vector3 vertexOut;
    vertexOut = azQuaternion1.TransformVector(vertexIn);

    bool same = AZVector3CompareClose(vertexOut, AZ::Vector3(0.0f, -0.1f, 0.0f), s_toleranceLow);
    ASSERT_TRUE(same);
}