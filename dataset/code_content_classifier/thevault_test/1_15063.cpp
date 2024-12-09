SGPFile* FileMan::openForWriting(const ST::string& filename, bool truncate)
{
	uint8_t open_options = FILE_OPEN_WRITE | FILE_OPEN_CREATE;
	if (truncate)
	{
		open_options |= FILE_OPEN_TRUNCATE;
	}

	RustPointer<VFile> file{File_open(filename.c_str(), open_options)};
	if (!file)
	{
		RustPointer<char> err{getRustError()};
		throw IoException(ST::format("FileMan::openForWriting('{}') failed: {}", filename, err.get()));
	}
	return new SGPFile(file.release());
}