AZ::Vector3* GenerateSegmentVertices(
            const AZ::Vector3& point,
            const AZ::Vector3& axis,
            const AZ::Vector3& normal,
            const float radius,
            const AZ::u32 sides,
            AZ::Vector3* vertices)
        {
            const auto deltaRot = AZ::Quaternion::CreateFromAxisAngle(
                axis, AZ::Constants::TwoPi / static_cast<float>(sides));

            auto currentNormal = normal;
            for (size_t i = 0; i < sides; ++i)
            {
                const auto localPosition = point + currentNormal * radius;
                vertices = WriteVertex(localPosition, vertices);
                currentNormal = deltaRot.TransformVector(currentNormal);
            }

            return vertices;
        }