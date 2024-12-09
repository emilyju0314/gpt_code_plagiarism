bool JsonUtility::writeToFile(const ST::string &name, const std::vector<ST::string> &strings)
{
	std::stringstream ss;
	rapidjson::OStreamWrapper os(ss);
	rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(os);
	writer.StartArray();
	for(auto it = strings.begin(); it != strings.end(); ++it)
	{
		writer.String(it->c_str());
	}
	writer.EndArray();
	ss << std::endl;

	ST::string buf = ss.str();
	try {
		AutoSGPFile file{FileMan::openForWriting(name)};

		file->write(buf.c_str(), buf.size());
	} catch (const std::runtime_error& ex) {
		SLOGE("JsonUtility::writeToFile: %s", ex.what());
		return false;
	}
	return true;
}