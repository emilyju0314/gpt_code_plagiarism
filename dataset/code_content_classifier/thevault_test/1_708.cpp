void NyxCmdOutputShell::printOutput(ostringstream &output,
                                    const std::string &query_name,
                                    std::string query_value)
{
	if (printOutputEnabled)
	{
		output << query_name << "='" << query_value << "'" << endl;
	}
}