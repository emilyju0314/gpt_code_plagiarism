String
    ShaderManager::getShaderLog(unsigned int shaderId)
    {
        String log;

        if (glIsShader(shaderId))
        {
            // Get info string length
            int infoLogLength = 0;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

            // Get info log
            CharArray infoLog(infoLogLength);
            glGetShaderInfoLog(shaderId, infoLogLength, &infoLogLength, infoLog.m_chars);
            log = String(infoLog.m_chars);
        }
        return log;
    }