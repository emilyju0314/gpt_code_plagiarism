MCore::Ray OrthographicCamera::Unproject(int32 screenX, int32 screenY)
    {
        AZ::Vector3  start = MCore::UnprojectOrtho(static_cast<float>(screenX), static_cast<float>(screenY), static_cast<float>(m_screenWidth), static_cast<float>(m_screenHeight), -1.0f, m_projectionMatrix, m_viewMatrix);
        AZ::Vector3  end = MCore::UnprojectOrtho(static_cast<float>(screenX), static_cast<float>(screenY), static_cast<float>(m_screenWidth), static_cast<float>(m_screenHeight), 1.0f, m_projectionMatrix, m_viewMatrix);

        return MCore::Ray(start, end);
    }