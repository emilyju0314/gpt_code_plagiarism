void NyxCmdOutput::printError(std::ostringstream &output,
                              const std::string &errorString)
{
	if (printErrorEnabled)
	{
		cerr << errorString << endl;
	}
}