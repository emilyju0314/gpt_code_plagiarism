TEST_F(EmotionFXMathLibTests, AZQuaternionConversion_FromMatrixXRot_Success)
{
    AZ::Matrix4x4 azMatrix = AZ::Matrix4x4::CreateRotationX(AZ::Constants::HalfPi);
    AZ::Quaternion azQuaternion = AZ::Quaternion::CreateFromMatrix4x4(azMatrix);

    AZ::Transform azTransform = AZ::Transform::CreateRotationX(AZ::Constants::HalfPi);
    AZ::Quaternion azQuaternionFromTransform = azTransform.GetRotation();

    AZ::Vector3 azVertexIn(0.0f, 0.1f, 0.0f);

    AZ::Vector3 azVertexOut = azQuaternion.TransformVector(azVertexIn);
    AZ::Vector3 emVertexOut = azQuaternionFromTransform.TransformVector(azVertexIn);

    bool same = AZVector3CompareClose(azVertexOut, emVertexOut, s_toleranceMedium);
    ASSERT_TRUE(same);
}