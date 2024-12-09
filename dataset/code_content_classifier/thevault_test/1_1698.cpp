std::pair<bool, configuration>
load(const std::pair<bool, etix::tool::opt_parse>& args) {
    std::string path;

    if (not args.second.exist("-c")) {
        path = etix::cameradar::default_configuration_path;
        LOG_WARN_("No custom path set, trying to use default path: " + path, "main");
    } else {
        path = args.second["-c"];
    }

    // Check if the file exists at the given path
    if (access(path.c_str(), F_OK) == -1) {
        LOG_ERR_("Can't access: " + path, "configuration");
        return std::make_pair(false, configuration{});
    }

    // Get the content of the file
    auto content = read_file(path);
    if (not content.first) {
        LOG_ERR_(
            "Can't open configuration file, you should check your rights to "
            "access the file",
            "configuration");
        return std::make_pair(false, configuration{});
    }

    // Parse & validate the json
    auto root = Json::Value();

    auto reader = Json::Reader();
    auto parse_succes = reader.parse(content.second, root);
    if (not parse_succes) {
        LOG_ERR_("Can't load configuration, invalid json format:\n" +
                     reader.getFormattedErrorMessages(),
                 "configuration");
        return std::make_pair(false, configuration{});
    }
    // Deserialize the json to a configuration struct
    // and return
    std::pair<bool, configuration> conf = serialize(root);
    conf.second.raw_conf = root;
    conf.first &= conf.second.load_url();
    conf.first &= conf.second.load_ids();

    if (args.second.exist("-s")) conf.second.target = args.second["-s"];
    if (args.second.exist("-p")) conf.second.target = args.second["-p"];

    return conf;
}