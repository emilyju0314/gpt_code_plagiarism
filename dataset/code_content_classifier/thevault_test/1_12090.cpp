TEST_P(Tests, FrustumContainsSphere_SphereInsidePlane_True)
    {
        AZ::Sphere testSphere = GenerateSphereInsidePlane(m_planes[m_testCase.plane], m_centerPoints[m_testCase.plane]);
        EXPECT_TRUE(AZ::ShapeIntersection::Contains(m_frustum, testSphere)) << "Frustum does not contain sphere even though sphere is completely inside the frustum." << std::endl << "Frustum:" << std::endl << m_testCase << std::endl << "Sphere:" << std::endl << testSphere << std::endl;
    }