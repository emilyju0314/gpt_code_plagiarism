AZStd::optional<AZStd::vector<AZ::Vector3>> CreatePointsAtFrustumExtents(float height, float bottomRadius, float topRadius, AZ::u8 subdivisions)
        {
            AZStd::vector<AZ::Vector3> points;

            if (height <= 0.0f)
            {
                AZ_Error("PhysX", false, "Frustum height %f must be greater than 0.", height);
                return {};
            }

            if (bottomRadius < 0.0f)
            {
                AZ_Error("PhysX", false, "Frustum bottom radius %f must be greater or equal to 0.", bottomRadius);
                return {};
            }
            else if (topRadius < 0.0f)
            {
                AZ_Error("PhysX", false, "Frustum top radius %f must be greater or equal to 0.", topRadius);
                return {};
            }
            else if (bottomRadius == 0.0f && topRadius == 0.0f)
            {
                AZ_Error("PhysX", false, "Either frustum bottom radius or top radius must be greater than to 0.");
                return {};
            }

            if (subdivisions < MinFrustumSubdivisions || subdivisions > MaxFrustumSubdivisions)
            {
                AZ_Error("PhysX", false, "Frustum subdivision count %u is not in [%u, %u] range", subdivisions, MinFrustumSubdivisions, MaxFrustumSubdivisions);
                return {};
            }

            points.reserve(subdivisions * 2);
            const float halfHeight = height * 0.5f;
            const double step = AZ::Constants::TwoPi / aznumeric_cast<double>(subdivisions);

            for (double rad = 0; rad < AZ::Constants::TwoPi; rad += step)
            {
                float x = aznumeric_cast<float>(std::cos(rad));
                float y = aznumeric_cast<float>(std::sin(rad));

                points.emplace_back(x * topRadius, y * topRadius, +halfHeight);
                points.emplace_back(x * bottomRadius, y * bottomRadius, -halfHeight);
            }

            return points;
        }