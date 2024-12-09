Reservoir EchoBay::esn_config(const Eigen::VectorXd &optParams, YAML::Node confParams, 
                         const int Nu, const int guess, const std::string folder)
{
    // ESN general Parameters
    // Deep ESN
    int nLayers = parse_config<int>("Nl", -1, 0, optParams, confParams, 1);
    // Esn Topology
    int type = 0;
    if (confParams["ESNType"])
    {
        type = confParams["ESNType"].as<int>();
    }
    // Sampling
    int nWashout = parse_config<int>("washout_sample", -1, 0, optParams, confParams, 10);
    // Problem settings
    double lambda = parse_config<double>("lambda", -1, 0, optParams, confParams, 0);

    // Build Reservoir object
    Reservoir ESN(nLayers, Nu, type);

    // Configure ESN
    ESN.init_LayerConfig(optParams, confParams);

    if (folder != "")
    {
        // Initialize Echo State Network: Win, Wr, stateMat
        ESN.load_network(folder);
    }
    else
    {
        ESN.init_network();
    }

    // Print parameters
    if (guess == 0)
    {
        std::cout << "\nTopology: " << ESNTypes[type] << std::endl;
        ESN.print_params(nLayers, nWashout, lambda);
    }

    return ESN;
}