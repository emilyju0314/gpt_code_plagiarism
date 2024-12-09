TEST_F(EmotionFXMathLibTests, AZQuaternion_EulerGetSet3ComponentAxisCompareTransform_Success)
{
    AZ::Vector3 axis = AZ::Vector3(1.0f, 0.7f, 0.3f);
    axis.Normalize();
    AZ::Quaternion azQuaternion1 = AZ::Quaternion::CreateFromAxisAngle(axis, AZ::Constants::HalfPi);
    AZ::Vector3 vertexIn(0.1f, 0.2f, 0.3f);
    AZ::Vector3 vertexOut1, vertexOut2, vertexTransform;
    AZ::Vector3 euler1, eulerVectorFromTransform;
    AZ::Quaternion test1, testTransformQuat;

    //generate vertex value 1
    vertexOut1 = azQuaternion1.TransformVector(vertexIn);

    //use Transform to generate euler
    AZ::Transform TransformFromQuat = AZ::Transform::CreateFromQuaternion(azQuaternion1);
    eulerVectorFromTransform = AZ::ConvertTransformToEulerRadians(TransformFromQuat);
    testTransformQuat = AZ::ConvertEulerRadiansToQuaternion(eulerVectorFromTransform);
    vertexTransform = testTransformQuat.TransformVector(vertexIn);

    //use existing convert function
    euler1 = AZ::ConvertQuaternionToEulerRadians(azQuaternion1);
    test1 = AZ::ConvertEulerRadiansToQuaternion(euler1);

    //generate vertex value 2
    vertexOut2 = test1.TransformVector(vertexIn);

    bool same = AZVector3CompareClose(vertexOut1, vertexTransform, s_toleranceReallyLow)
        && AZVector3CompareClose(vertexOut1, vertexOut2, s_toleranceReallyLow)
        && AZVector3CompareClose(vertexOut2, vertexTransform, s_toleranceHigh);
    ASSERT_TRUE(same);
}