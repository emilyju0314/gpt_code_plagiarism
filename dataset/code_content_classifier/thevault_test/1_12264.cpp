TEST_F(EmotionFXMathLibTests, AZQuaternion_EulerGetSet2ComponentAxis_Success)
{
    AZ::Vector3 axis = AZ::Vector3(0.0f, 0.7f, 0.3f);
    axis.Normalize();
    AZ::Quaternion azQuaternion1 = AZ::Quaternion::CreateFromAxisAngle(axis, AZ::Constants::HalfPi);
    AZ::Vector3 vertexIn(0.1f, 0.2f, 0.3f);
    AZ::Vector3 vertexOut1, vertexOut2;
    AZ::Vector3 euler1;
    AZ::Quaternion test1;

    //generate vertex value 1
    vertexOut1 = azQuaternion1.TransformVector(vertexIn);

    //euler out and in
    euler1 = AZ::ConvertQuaternionToEulerRadians(azQuaternion1);
    test1 = AZ::ConvertEulerRadiansToQuaternion(euler1);

    //generate vertex value 2
    vertexOut2 = test1.TransformVector(vertexIn);

    bool same = AZVector3CompareClose(vertexOut1, vertexOut2, s_toleranceReallyLow);
    ASSERT_TRUE(same);
}