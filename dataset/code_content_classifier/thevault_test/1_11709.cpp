std::string ClientHandler::searchFile(std::string filename) {
	for (auto dir : FileSystem::Directory::getDirectories("../TestFileServer/")) {
		if (dir != "." && dir != "..") {
			std::vector<std::string> files = FileSystem::Directory::getFiles("../TestFileServer/" + dir, filename);
			if (files.size() == 0) continue;
			else return "../TestFileServer/" + dir + "/" + filename;
		}
	}
	return "";
}