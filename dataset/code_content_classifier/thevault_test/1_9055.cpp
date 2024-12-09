void QueryParser::replacePrefix(string &str)
{
	if (str[0] != '<' && str[0] != '\"' && str[0] != '?')
	{
		int sep = str.find(":");
		if (sep == -1)	return;

		string prefix = str.substr(0, sep + 1);

		//blank node
		if (prefix == "_:")	return;

		printf("prefix = %s\n", prefix.c_str());
		if (this->prefix_map.count(prefix) != 0)
		{
			str = this->prefix_map[prefix].substr(0, this->prefix_map[prefix].length() - 1) + str.substr(sep + 1 ,str.length() - sep - 1) + ">";
			printf("str = %s\n",str.c_str());
		}
		else
		{
			printf("prefix not found...\n");
			throw runtime_error("[ERROR]	Prefix is not found, please define it before use.");
		}
	}
}