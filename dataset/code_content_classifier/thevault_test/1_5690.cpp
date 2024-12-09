void EchoBay::Reservoir::init_WrLayers()
{
    // Clear Wr vector
    WrLayers.clear();
    // Fill layers
    for(const auto& layer: _layerConfig)
    {
        WrLayers.push_back(init_Wr(layer.Nr, layer.density, layer.desiredRho, layer.leaky, layer.edgesJumps));
    }
}