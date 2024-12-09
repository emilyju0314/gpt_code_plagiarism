void MorphTargetStandard::ApplyTransformation(ActorInstance* actorInstance, size_t nodeIndex, AZ::Vector3& position, AZ::Quaternion& rotation, AZ::Vector3& scale, float weight)
    {
        // calculate the normalized weight (in range of 0..1)
        const float newWeight = MCore::Clamp<float>(weight, m_rangeMin, m_rangeMax); // make sure its within the range
        const float normalizedWeight = CalcNormalizedWeight(newWeight); // convert in range of 0..1

        // calculate the new transformations for all nodes of this morph target
        for (const Transformation& transform : m_transforms)
        {
            // if this is the node that gets modified by this transform
            if (transform.m_nodeIndex != nodeIndex)
            {
                continue;
            }

            position += transform.m_position * newWeight;
            scale += transform.m_scale * newWeight;

            // rotate additively
            const AZ::Quaternion& orgRot = actorInstance->GetTransformData()->GetBindPose()->GetLocalSpaceTransform(nodeIndex).m_rotation;
            const AZ::Quaternion rot = orgRot.NLerp(transform.m_rotation, normalizedWeight);
            rotation = rotation * (orgRot.GetInverseFull() * rot);
            rotation.Normalize();

            // all remaining nodes in the transform won't modify this current node
            break;
        }
    }