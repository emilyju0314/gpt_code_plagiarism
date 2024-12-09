GLuint load_shader(std::string path, GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);

	std::string file_contents = load_file(path);

	const GLchar* file_data = file_contents.c_str();

	glShaderSource(shader, 1, &file_data, NULL);

	glCompileShader(shader);

	GLint success = 0;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		std::cout << "Could not compile shader loaded from \"" << path << "\"." << std::endl;

		GLchar crash_information[4096];

		glGetShaderInfoLog(shader, 4096, NULL, crash_information);

		std::cout << crash_information;

		exit(7);
	}

	return shader;
}