static std::map<std::string, std::string> argvToMap(int argc, char* argv[]) {
	std::map<std::string, std::string> args;
	size_t i = 1;
	while (i != argc) {
		std::string firstArg(argv[i]);
		if (hyperloop::startsWith(firstArg, '-')) {
			if (i+1 < argc) {
				args[firstArg] = std::string(argv[i+1]);
			} else {
				args[firstArg] = "true";
			}
		}
		++i;
	}
	return args;
}