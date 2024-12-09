TEST_F(EmotionFXMathLibTests, AZQuaternionConversion_FromAZTransformXRot_Success)
{
    AZ::Transform azTransform = AZ::Transform::CreateRotationX(AZ::Constants::HalfPi);
    AZ::Quaternion azQuaternion = azTransform.GetRotation();

    AZ::Vector3 emVertexIn(0.0f, 0.1f, 0.0f);
    AZ::Vector3 emVertexOut = azQuaternion.TransformVector(emVertexIn);

    bool same = AZVector3CompareClose(emVertexOut, 0.0f, 0.0f, 0.1f, s_toleranceMedium);
    ASSERT_TRUE(same);
}