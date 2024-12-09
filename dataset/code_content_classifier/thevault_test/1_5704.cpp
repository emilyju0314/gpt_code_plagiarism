floatBO EchoBay::Reservoir::return_net_dimension(const YAML::Node confParams) const
{
    int optNr = 0,optDensity = 0;
    floatBO NrUpper, NrLower, densityUpper, densityLower;

    if (confParams["Nr"]["type"].as<std::string>() == "dynamic")
    {
        optNr = 1;
        NrUpper = confParams["Nr"]["upper_bound"].as<int>();
        NrLower = confParams["Nr"]["lower_bound"].as<int>();
    }

    if (confParams["density"]["type"].as<std::string>() == "dynamic")
    {
        optDensity = 1;
        densityUpper = confParams["density"]["upper_bound"].as<floatBO>();
        densityLower = confParams["density"]["lower_bound"].as<floatBO>();
    }

    floatBO count;
    count = (optNr + optDensity) * _nLayers == 0 ? 1 : (optNr + optDensity) * _nLayers;
    floatBO memory = 0;
    for (int i = 0; i < _nLayers; ++i)
    {
        floatBO tempNr, tempDensity;
        if(optNr){
            tempNr = (_layerConfig[i].Nr - NrLower)/(NrUpper - NrLower);
            memory += tempNr;
        }
        if(optDensity){
            tempDensity =  (_layerConfig[i].density - densityLower)/(densityUpper - densityLower);
            memory += tempDensity;
        }
        
    }
    return memory/count;
}