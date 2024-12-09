DualQuaternion DualQuaternion::ConvertFromTransform(const AZ::Transform& transform)
    {
        const AZ::Vector3 pos = transform.GetTranslation();
        const AZ::Quaternion rot = transform.GetRotation();
        return DualQuaternion(rot, pos);
    }