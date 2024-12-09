void EchoBay::Reservoir::load_WinLayers(const std::string &folder)
{

    MatrixBO Win;
    std::string tempName;
    for (int i = 0; i < _nLayers; ++i)
    {
        tempName = folder + "/Win_eigen" + std::to_string(i) + ".mtx";
        read_matrix(tempName, Win);
        WinLayers.push_back(Win);
    }
}