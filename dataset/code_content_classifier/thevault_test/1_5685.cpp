EchoBay::Reservoir::Reservoir(const int nLayers, const int Nu, const int type)
{
    // Save layers
    _nLayers = nLayers;
    // Save input
    _Nu = Nu;
    // Save type
    _type = type;
    // Reserve vectors
    WinLayers.reserve(_nLayers);
    WrLayers.reserve(_nLayers);
    stateMat.reserve(_nLayers);
    _layerConfig.reserve(_nLayers);
}