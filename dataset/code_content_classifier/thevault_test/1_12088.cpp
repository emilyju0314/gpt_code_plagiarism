TEST_P(Tests, FrustumContainsSphere_SphereOutsidePlane_False)
    {
        AZ::Sphere testSphere = GenerateSphereOutsidePlane(m_planes[m_testCase.plane], m_centerPoints[m_testCase.plane]);
        EXPECT_FALSE(AZ::ShapeIntersection::Contains(m_frustum, testSphere)) << "Frustum contains sphere even though sphere is completely outside the frustum." << std::endl << "Frustum:" << std::endl << m_testCase << std::endl << "Sphere:" << std::endl << testSphere << std::endl;
    }