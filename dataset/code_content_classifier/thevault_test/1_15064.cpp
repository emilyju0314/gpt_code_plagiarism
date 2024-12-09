SGPFile* FileMan::openForAppend(const ST::string& filename)
{
	RustPointer<VFile> file{File_open(filename.c_str(), FILE_OPEN_APPEND | FILE_OPEN_CREATE)};
	if (!file)
	{
		RustPointer<char> err{getRustError()};
		throw IoException(ST::format("FileMan::openForAppend('{}') failed: {}", filename, err.get()));
	}
	return new SGPFile(file.release());
}