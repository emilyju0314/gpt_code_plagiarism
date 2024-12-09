string ExecCommand(const char* cmd)
{
	char buffer[128];
	string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw runtime_error("popen() failed!");
	try
	{
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
	}
	catch (exception& e)
	{
		_pclose(pipe);
		throw e;
	}
	catch (...)
	{
		throw ExecCommandException();
	}
	_pclose(pipe);
	return result;
}