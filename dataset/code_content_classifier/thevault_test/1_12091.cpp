TEST_P(Tests, SphereOverlapsFrustum_SphereInsidePlane_True)
    {
        AZ::Sphere testSphere = GenerateSphereInsidePlane(m_planes[m_testCase.plane], m_centerPoints[m_testCase.plane]);
        EXPECT_TRUE(AZ::ShapeIntersection::Overlaps(testSphere, m_frustum)) << "Sphere does not overlap frustum even though sphere is completely inside the frustum." << std::endl << "Frustum:" << std::endl << m_testCase << std::endl << "Sphere:" << std::endl << testSphere << std::endl;
    }