EchoBay::Reservoir::~Reservoir()
{
    // Free vectors
    _layerConfig.clear();
    _layerConfig.shrink_to_fit();
    WinLayers.clear();
    WinLayers.shrink_to_fit();
    WrLayers.clear();
    WrLayers.shrink_to_fit();
    stateMat.clear();
    stateMat.shrink_to_fit();
}