GLuint CreateAndCompileShader(GLenum shaderType, const char * source) {
		ASSERTM(source, "[OpenGL] Invalid shader string");

		GLuint id = glCreateShader(shaderType);
		ASSERT(id);

		int success;
		char infoLog[512];

		glShaderSource(id, 1, &source, nullptr);
		glCompileShader(id);

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(id, sizeof(infoLog), nullptr, infoLog);
			switch (shaderType) {
			case GL_VERTEX_SHADER:
			{
				LOG_ERROR("Vertex Shader Compilation Failed:");
				break;
			}
			case GL_FRAGMENT_SHADER:
			{
				LOG_ERROR("Fragment Shader Compilation Failed:");
				break;
			}
			}
			LOG_ERROR("%s", infoLog);
			ASSERTM(false, "Fatal Error");
		}

		return id;
	}