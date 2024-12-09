TEST_F(EmotionFXMathLibTests, AZQuaternionConversion_FromAZTransformYRot_Success)
{
    AZ::Transform azTransform = AZ::Transform::CreateRotationY(AZ::Constants::HalfPi);
    AZ::Quaternion azQuaternion = azTransform.GetRotation();

    AZ::Vector3 emVertexIn(0.0f, 0.0f, 0.1f);
    AZ::Vector3 emVertexOut = azQuaternion.TransformVector(emVertexIn);

    bool same = AZVector3CompareClose(emVertexOut, 0.1f, 0.0f, 0.0f, s_toleranceMedium);
    ASSERT_TRUE(same);
}