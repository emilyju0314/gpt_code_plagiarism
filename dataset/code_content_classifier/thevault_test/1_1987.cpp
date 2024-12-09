void *api::OcelotConfiguration::configuration() const {
	std::ifstream file(path.c_str());
	hydrazine::json::Parser parser;
	hydrazine::json::Object *config = 0;
	try {
		config = parser.parse_object(file);
	}
	catch (hydrazine::Exception exp) {
		std::cerr << "==Ocelot== WARNING: Could not parse config file '" 
			<< path << "', loading defaults.\n" << std::endl;
			
		std::cerr << "exception:\n" << exp.what() << std::endl;
	}
	return config;
}