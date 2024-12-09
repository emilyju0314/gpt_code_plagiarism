static void procCmdLine(int argc, char **argv, ParamArgData &argData)
{
    // Define and parse the program options
    po::options_description commandLine("Program Options");
    commandLine.add_options()("help", "Print help messages")("config,c", po::value<std::string>(&argData.configFileName), "Config File Name");
    addCommonOptions(commandLine, argData);
    po::options_description configFile("Config Files Options");
    addCommonOptions(configFile, argData);
    po::variables_map vm;
    try
    {
        // Process arguments
        po::store(po::parse_command_line(argc, argv, commandLine), vm);
        // Display options and exit with success
        if (vm.count("help"))
        {
            std::cout << "ITCFTP" << std::endl
                      << commandLine << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (vm.count("config"))
        {
            if (CFile::exists(vm["config"].as<std::string>()))
            {
                std::ifstream configFileStream{vm["config"].as<std::string>()};
                if (configFileStream)
                {
                    po::store(po::parse_config_file(configFileStream, configFile), vm);
                }
            }
            else
            {
                throw po::error("Specified config file does not exist.");
            }
        }
        po::notify(vm);
    }
    catch (po::error &e)
    {
        std::cerr << "ITCFTP Error: " << e.what() << std::endl
                  << std::endl;
        std::cerr << commandLine << std::endl;
        exit(EXIT_FAILURE);
    }
}