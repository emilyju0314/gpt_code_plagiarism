static auto compileShaderStage(GLuint const id, char const* const name,
	char const* const source) -> bool
{
	ASSERT(id);
	ASSERT(name);
	ASSERT(source);

	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	GLint const compileStatus = [=] {
		GLint status = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &status);
		return status;
	}();
	if (compileStatus == GL_FALSE) {
		auto const infoLog = [=] {
			array<GLchar, 2048> log = {};
			glGetShaderInfoLog(id, log.size(), nullptr, log.data());
			return log;
		}();
		L.error(R"(Shader "{}" failed to compile: {})", name, infoLog.data());
		return false;
	}
	return true;
}