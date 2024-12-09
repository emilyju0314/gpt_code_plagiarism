void EchoBay::Reservoir::init_LayerConfig(std::vector<stringdouble_t> paramValue) // TO DO, if necessary, updated with different types
{
    _layerConfig.clear();
    int nLayers = paramValue[0]["Nl"](0);
    int countScale = paramValue[0]["scaleInCount"](0);
    int scaleSize;
    for (int i = 0; i < nLayers; i++)
    {
        layerParameter layerTemp;
        layerTemp.Nr = paramValue[i]["Nr"](0);
        layerTemp.density = paramValue[i]["density"](0);
        layerTemp.desiredRho = paramValue[i]["rho"](0);
        layerTemp.leaky = paramValue[i]["leaky"](0);
        // scaleInput management
        scaleSize = (i == 0) ? _Nu : 1;
        layerTemp.scaleInput.resize(scaleSize);
        layerTemp.scaleInput[0] = paramValue[i]["scaleIn"](0);
        for (int j = 1; (j < countScale) && (i == 0); j++)
        {
            layerTemp.scaleInput[j] = paramValue[i]["scaleIn"](j);
        }
        for (int j = countScale; (j < _Nu) && (i == 0); j++)
        {
            layerTemp.scaleInput[j] = layerTemp.scaleInput[countScale - 1];
        }
        _layerConfig.push_back(layerTemp);
    }
}