unsigned int
    ShaderManager::createProgram(String const& rName)
    {
        // Create shaders
        auto const shaderSourceFileTemplate = String("resource/%.%").arg(rName);
        auto const vertexShaderId = createShaderFromString(readStringFromFile(shaderSourceFileTemplate.arg("glvs")), EShaderType::Vertex);
        auto const fragmentShaderId = createShaderFromString(readStringFromFile(shaderSourceFileTemplate.arg("glfs")), EShaderType::Fragment);

        // Create program
        auto const programId = glCreateProgram();
        glAttachShader(programId, vertexShaderId);
        glAttachShader(programId, fragmentShaderId);

        // Link program
        glLinkProgram(programId);

        // Check program
        auto ok = GL_FALSE;
        glGetProgramiv(programId, GL_LINK_STATUS, &ok);
        if (ok != GL_TRUE)
            throw std::exception(String("Graphics error: %").arg(getProgramLog(programId)).c_str());

        // Clean up
        glDetachShader(programId, vertexShaderId);
        glDetachShader(programId, fragmentShaderId);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);

        return programId;
    }