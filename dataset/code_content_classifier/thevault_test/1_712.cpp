void NyxCmdOutputJson::printOutput(ostringstream &output,
                                   const std::string &query_name,
                                   std::string query_value)
{
	if (printOutputEnabled)
	{
		ReplaceStringInPlace(query_value, "\n", "\\n");
		ReplaceStringInPlace(query_value, "\"", "\\\"");
		output << "    \"" << query_name << "\": \"" << query_value
		       << "\"," << endl;
	}
}