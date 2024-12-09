void NyxCmdOutputShell::printOutput(ostringstream &output,
                                    const std::string &query_name,
                                    const int &query_value)
{
	if (printOutputEnabled)
	{
		output << query_name << "='" << query_value << "'" << endl;
	}
}