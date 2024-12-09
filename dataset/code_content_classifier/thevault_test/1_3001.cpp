Configuration *Configuration::Path(const char *_path)
{
	StringCchCopyA(path, 2048, _path);

	return this;
}