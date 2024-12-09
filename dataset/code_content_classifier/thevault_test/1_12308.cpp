bool PlaneEq::Clip(AZStd::vector<AZ::Vector3>& points) const
    {
        AZStd::vector<AZ::Vector3> pointsOut;
        if (Clip(points, pointsOut))
        {
            points = pointsOut;
            return true;
        }

        return false;
    }