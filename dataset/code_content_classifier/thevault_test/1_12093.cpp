TEST_P(Tests, SphereOverlapsFrustum_SphereHalfInsideHalfOutsidePlane_True)
    {
        AZ::Sphere testSphere(m_centerPoints[m_testCase.plane], m_minEdgeLength * .25f);
        EXPECT_TRUE(AZ::ShapeIntersection::Overlaps(testSphere, m_frustum)) << "Sphere does not overlap frustum even though sphere is partially inside the frustum." << std::endl << "Frustum:" << std::endl << m_testCase << std::endl << "Sphere:" << std::endl << testSphere << std::endl;
    }