AZ::Vector3 GenerateNoiseyVector(const AZ::Vector3& in, const Vector3& noise, NoiseSource source)
    {
        switch (source)
        {
        case NoiseSource::None:
            return in;
        case NoiseSource::XComponent:
            return AZ::Vector3(in.GetX() + noise.x, in.GetY(), in.GetZ());
        case NoiseSource::YComponent:
            return AZ::Vector3(in.GetX(), in.GetY() + noise.y, in.GetZ());
        case NoiseSource::ZComponent:
            return AZ::Vector3(in.GetX(), in.GetY(), in.GetZ() + noise.z);
        case NoiseSource::XYComponent:
            return AZ::Vector3(in.GetX() + noise.x, in.GetY() + noise.y, in.GetZ());
        case NoiseSource::XZComponent:
            return AZ::Vector3(in.GetX() + noise.x, in.GetY(), in.GetZ() + noise.z);
        case NoiseSource::YZComponent:
            return AZ::Vector3(in.GetX(), in.GetY() + noise.y, in.GetZ() + noise.z);
        case NoiseSource::XYZComponent:
            return AZ::Vector3(in.GetX() + noise.x, in.GetY() + noise.y, in.GetZ() + noise.z);

        default:
            return in;
        }
    }