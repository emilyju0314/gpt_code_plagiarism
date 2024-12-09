void CsvWorker::loadFromFile(std::string filename)
{
    // Load file data
	std::deque<std::string> readed_data;
	loadFile(filename, readed_data);
	// Parse readed data
	parseData(readed_data);
}