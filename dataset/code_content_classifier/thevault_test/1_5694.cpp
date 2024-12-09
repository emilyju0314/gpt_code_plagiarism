void EchoBay::Reservoir::load_stateMat(const std::string &folder)
{
    // First layer
    ArrayBO state;
    std::string tempName;
    for (int i = 0; i < _nLayers; ++i)
    {
        tempName = folder + "/State_eigen" + std::to_string(i) + ".mtx";
        read_matrix(tempName, state);
        stateMat.push_back(state);
    }
}