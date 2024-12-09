std::string GetWorkingDirectory()
	{
#if defined(MONOCLE_WINDOWS)
		char buffer[256];
		::GetCurrentDirectory(256, (char*)&buffer);
		return std::string(buffer) + + "\\";
#elif defined(MONOCLE_LINUX)
        char buffer[FILENAME_MAX];
        getcwd(buffer, sizeof(buffer));
		return std::string(buffer) + "\\";
#else
		return "";
#endif
	}