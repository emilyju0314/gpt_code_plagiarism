std::string FileOperation::findFileName(std::string path)
{
	int i, last;
	for (i = 0; path[i]; i++)
		if (path[i] == '\\')
			last = i;
	return path.substr(last + 1);
}