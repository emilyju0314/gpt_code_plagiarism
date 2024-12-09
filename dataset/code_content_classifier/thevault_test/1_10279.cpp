String
    ShaderManager::getProgramLog(unsigned int programId)
    {
        String log;
        if (glIsProgram(programId))
        {
            // Get info string length
            int infoLogLength = 0;
            glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);

            // Get info log
            CharArray infoLog(infoLogLength);
            glGetProgramInfoLog(programId, infoLogLength, &infoLogLength, infoLog.m_chars);
            log = String(infoLog.m_chars);
        }
        return log;
    }