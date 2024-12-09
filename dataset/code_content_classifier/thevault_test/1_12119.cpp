static bool SimplePolygon(const AZStd::vector<AZ::Vector2>& vertices)
    {
        const size_t vertexCount = vertices.size();

        if (vertexCount < 3)
        {
            return false;
        }

        if (vertexCount == 3)
        {
            return true;
        }

        for (size_t i = 0; i < vertexCount; ++i)
        {
            // make it easy to nicely wrap indices
            const size_t safeIndex = i + vertexCount;

            const size_t endIndex = (safeIndex - 1) % vertexCount;
            const size_t beginIndex = (safeIndex + 2) % vertexCount;

            for (size_t j = beginIndex; j != endIndex; j = (j + 1) % vertexCount)
            {
                float aa, bb;
                AZ::Vector3 a, b;
                AZ::Intersect::ClosestSegmentSegment(
                    AZ::Vector2ToVector3(vertices[i]),
                    AZ::Vector2ToVector3(vertices[(i + 1) % vertexCount]),
                    AZ::Vector2ToVector3(vertices[j]),
                    AZ::Vector2ToVector3(vertices[(j + 1) % vertexCount]),
                    aa, bb, a, b);

                if ((a - b).GetLength() < 0.001f)
                {
                    return false;
                }
            }
        }

        return true;
    }