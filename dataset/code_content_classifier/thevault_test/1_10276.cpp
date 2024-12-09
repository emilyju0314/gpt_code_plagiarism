unsigned int
    ShaderManager::createShaderFromString(String const& rShaderString, EShaderType shaderType)
    {
        unsigned int shaderId = 0;

        // Create
        switch (shaderType)
        {
        case EShaderType::Vertex:
            shaderId = glCreateShader(GL_VERTEX_SHADER);
            break;
        case EShaderType::Fragment:
            shaderId = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        }

        // Set source
        auto const* source = rShaderString.c_str();
        glShaderSource(shaderId, 1, &source, NULL);

        // Compile
        glCompileShader(shaderId);

        // Check
        auto ok = GL_FALSE;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &ok);
        if (ok != GL_TRUE)
            throw std::exception(String("Graphics error: Unable to compile shader %:\n%\n\n%")
                                 .arg(shaderId)
                                 .arg(rShaderString)
                                 .arg(getShaderLog(shaderId)).c_str());

        return shaderId;
    }