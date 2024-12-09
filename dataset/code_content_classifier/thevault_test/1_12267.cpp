TEST_F(EmotionFXMathLibTests, AZQuaternionConversion_ToEulerEquivalent_Success)
{
    AZ::Vector3 eulerIn(0.1f, 0.2f, 0.3f);
    AZ::Vector3 testVertex(0.1f, 0.2f, 0.3f);
    AZ::Vector3 outVertex1, outVertex2;
    AZ::Quaternion test, test2;
    AZ::Vector3 eulerOut1, eulerOut2;

    test = AZ::ConvertEulerRadiansToQuaternion(eulerIn);
    test.Normalize();
    outVertex1 = test.TransformVector(testVertex);

    eulerOut1 = AZ::ConvertQuaternionToEulerRadians(test);

    test2 = AZ::ConvertEulerRadiansToQuaternion(eulerOut1);
    test2.Normalize();
    outVertex2 = test2.TransformVector(testVertex);

    eulerOut2 = AZ::ConvertQuaternionToEulerRadians(test2);
    ASSERT_TRUE(AZVector3CompareClose(eulerOut1, eulerOut2, s_toleranceReallyLow));
}