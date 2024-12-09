void save_config(const std::string &filename, YAML::Node YAML_CONF, const Eigen::VectorXd x)
{
    int idx;
    
    std::string variableName;    
    std::ofstream outputFile;

    //Output destination as configuration param??
    outputFile.open(filename, std::ios::out);
    YAML::Emitter output_emit;
    
    YAML::Node confCopy;
    confCopy = YAML_CONF;
    output_emit << YAML::BeginDoc;

    int nLayers = confCopy["Nl"]["value"].as<int>();
    int nDofLayer = confCopy["input_dimension_layer"].as<int>(); // Number of optimizable parameters per layer
    int nDofOffset = confCopy["input_dimension_general"].as<int>(); // Number of optimizable parameters general

    int scaleInCount = 1;// = confCopy["scaleIn"]["count"].as<int>();
    std::string scaleInType = confCopy["scaleIn"]["type"].as<std::string>();
    if (scaleInType == "dynamic")
    {
        if(confCopy["scaleIn"]["count"]){
            // Check count minimum size
            scaleInCount = confCopy["scaleIn"]["count"].as<int>() >= 2 ? confCopy["scaleIn"]["count"].as<int>() : 2;
        }else{
            scaleInCount = 1;
        }
    }

    std::vector<int> indices;
    std::vector<std::string> names;
    
    for (auto it = tMapGeneral.cbegin(); it != tMapGeneral.cend(); ++it)
    {  
        variableName = it->first;
        if (confCopy[variableName])
        {
            if (confCopy[variableName]["type"].as<std::string>() == "dynamic")
            {
                indices.push_back(confCopy[variableName]["index"].as<int>());
                names.push_back(variableName);
            }
        }
    }

    std::string layerNumber;
    for (int i = 0; i < nLayers; i++)
    {   
        layerNumber = "L" +std::to_string(i) ;

        for (auto it = tMapLayer.cbegin(); it != tMapLayer.cend(); ++it)
        {  
            variableName = it->first;
            if (confCopy[variableName])
            {
                if (confCopy[variableName]["type"].as<std::string>() == "dynamic")
                {

                    idx = confCopy[variableName]["index"].as<int>();
                    indices.push_back(idx + i*nDofLayer + nDofOffset);
                    names.push_back(variableName+layerNumber);
                }
            }
        }
    }
    
    int maxOffset = nLayers * nDofLayer + nDofOffset;
    if (scaleInCount > 1)
    {
        for (int i = maxOffset; i < maxOffset + scaleInCount-1; ++i)
        {
            indices.push_back(i);
            names.push_back("extraScaleIn");
        }
    }


    for (int i = 0; i < x.size(); ++i)
    {
        std::stringstream roundedValue;

        roundedValue << std::setprecision(5)
                     << std::fixed << x(i); 
        confCopy["x"].push_back(roundedValue.str());
    }
    confCopy["x"].SetStyle(YAML::EmitterStyle::Flow);

    std::string comment;

    for (auto i: sort_indexes(indices)) {
      comment += names[i] + " ";
    }

    output_emit << confCopy;
    output_emit << YAML::Comment(comment);

    output_emit << YAML::EndDoc;

    // Emit file
    outputFile << output_emit.c_str();
    outputFile.close();
}