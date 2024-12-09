bool file_exists(const char* fname)
{
	std::ifstream fs(fname);
	return fs.good();
}