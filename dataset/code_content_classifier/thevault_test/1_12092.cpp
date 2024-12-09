TEST_P(Tests, FrustumContainsSphere_SphereHalfInsideHalfOutsidePlane_False)
    {
        AZ::Sphere testSphere(m_centerPoints[m_testCase.plane], m_minEdgeLength * .25f);
        EXPECT_FALSE(AZ::ShapeIntersection::Contains(m_frustum, testSphere)) << "Frustum contains sphere even though sphere is partially outside the frustum." << std::endl << "Frustum:" << std::endl << m_testCase << std::endl << "Sphere:" << std::endl << testSphere << std::endl;
    }