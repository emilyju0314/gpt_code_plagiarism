void EchoBay::Reservoir::init_LayerConfig(const Eigen::VectorXd &optParams, const YAML::Node confParams)
{
    // Reset layerConfig
    _layerConfig.clear();
    int nLayers = parse_config<int>("Nl", 0, 0, optParams, confParams, 1);
    int countScale = 1;
    int NrTemporary;
    // if (confParams["scaleIn"]["count"])
    // {
    //     countScale = confParams["scaleIn"]["count"].as<int>();
    // }
    std::string scaleInType = confParams["scaleIn"]["type"].as<std::string>();
    if (scaleInType == "dynamic")
    {
        if(confParams["scaleIn"]["count"]){
            // Check count minimum size
            countScale = confParams["scaleIn"]["count"].as<int>() >= 2 ? confParams["scaleIn"]["count"].as<int>() : 2;
        }else{
            countScale = 2;

        }
    }else{
        countScale = 1;
    }
    // Get reservoir scaling type
    if (confParams["rho"]["scaling"])
    {
        _reservoirInizialization = confParams["rho"]["scaling"].as<std::string>();
    }

    int scaleSize;
    for (int i = 0; i < nLayers; i++)
    {
        layerParameter layerTemp;
        NrTemporary = parse_config<int>("Nr", i, 0, optParams, confParams, 400);
        layerTemp.Nr = NrTemporary >= 2 ? NrTemporary : 2;
        layerTemp.density = parse_config<double>("density", i, 0, optParams, confParams, 1);
        layerTemp.desiredRho = parse_config<double>("rho", i, 0, optParams, confParams, 0.9);
        layerTemp.leaky = parse_config<double>("leaky", i, 0, optParams, confParams, 0.9);
        layerTemp.edgesJumps = parse_config<int>("edgesJumps", i, 0, optParams, confParams, 0);

        // scaleInput management
        scaleSize = (i == 0) ? _Nu : 1;
        layerTemp.scaleInput.resize(scaleSize);
        layerTemp.scaleInput[0] = parse_config<double>("scaleIn", i, 0, optParams, confParams, 1);

        for (int j = 1; (j < countScale) && (i == 0); j++)
        {
            layerTemp.scaleInput[j] = parse_config<double>("scaleIn", nLayers, j, optParams, confParams, 1);
        }
        for (int j = countScale; (j < _Nu) && (i == 0); j++)
        {
            layerTemp.scaleInput[j] = layerTemp.scaleInput[countScale - 1];
        }
        _layerConfig.push_back(layerTemp);
    }
     
    // Manage Small World topology
    if (_type == 1)
    {
        int elementsToCopy;
        ArrayI InIndex;
        ArrayI OutIndex;
        for (int i = 0; i < nLayers; ++i)
        {
            elementsToCopy = (int) floor(_layerConfig[i].Nr /5.0);
            InIndex.resize(elementsToCopy);
            OutIndex.resize(elementsToCopy);
            for (int j = 0; j < elementsToCopy; ++j)
            {
                InIndex[j] = j;
                OutIndex[j] = j + (int) floor(_layerConfig[i].Nr /2.0);
            }
            _WinIndex.push_back(InIndex);
            _WoutIndex.push_back(OutIndex);
        }
          
    }

}