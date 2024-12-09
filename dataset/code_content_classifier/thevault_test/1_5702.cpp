int EchoBay::Reservoir::get_fullNr(const int layer) const
{
    auto sumNr = [](int sum, const layerParameter& curr){return sum + curr.Nr;};
    auto finalLayer = (layer == -1) ? _layerConfig.end() : _layerConfig.begin() + layer;

    return 1 + std::accumulate(_layerConfig.begin(), finalLayer, 0, sumNr);
}