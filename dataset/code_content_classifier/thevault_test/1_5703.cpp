int EchoBay::Reservoir::get_NrSWT(const int layer) const
{
    auto sumNrSWT = [](int sum, const ArrayI curr){return sum + curr.size();};
    auto finalLayer = (layer == -1) ? _WoutIndex.end() : _WoutIndex.begin() + layer;

    return 1 + std::accumulate(_WoutIndex.begin(), finalLayer, 0, sumNrSWT);
}