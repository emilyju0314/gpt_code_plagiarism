void CsvWorker::loadFile(std::string filename, std::deque<std::string> &readed_data)
{
	// File to read
	FILE *fin;
	char buffer[BLOCK_SIZE];
	int ok = fopen_s(&fin, filename.c_str(), "rb");
	if (!ok) {
		// The end of the file
		_fseeki64(fin, 0, SEEK_END);
		// Get size of the file
		long long m_file_size = _ftelli64(fin);
		// Go to start
		_fseeki64(fin, 0, SEEK_SET);
		// Read and write by "BLOCK_SIZE" bytes
		int blocks_count = m_file_size / BLOCK_SIZE;
		for (size_t i = 0; i <= blocks_count; ++i) {
			int readed = fread(buffer, sizeof(unsigned char), BLOCK_SIZE, fin);
			readed_data.push_back(std::string((char*)buffer, readed));
		}
		fclose(fin);
	}
	else
	{
		cout << "Can't open file \"" << filename << '\"' << endl;
		throw;
	}
}