MCore::Ray Camera::Unproject(int32 screenX, int32 screenY)
    {
        const AZ::Matrix4x4 invProj = MCore::InvertProjectionMatrix(m_projectionMatrix);
        const AZ::Matrix4x4 invView = MCore::InvertProjectionMatrix(m_viewMatrix);

        const AZ::Vector3  start = MCore::Unproject(static_cast<float>(screenX), static_cast<float>(screenY), static_cast<float>(m_screenWidth), static_cast<float>(m_screenHeight), m_nearClipDistance, invProj, invView);
        const AZ::Vector3  end   = MCore::Unproject(static_cast<float>(screenX), static_cast<float>(screenY), static_cast<float>(m_screenWidth), static_cast<float>(m_screenHeight), m_farClipDistance, invProj, invView);

        return MCore::Ray(start, end);
    }