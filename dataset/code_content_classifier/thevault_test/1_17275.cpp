std::string load_file(std::string path)
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cout << "Could not open file \"" << path << "\"." << std::endl;

		exit(6);
	}

	std::stringstream buffer;

	buffer << file.rdbuf() << "\0";

	return buffer.str();
}