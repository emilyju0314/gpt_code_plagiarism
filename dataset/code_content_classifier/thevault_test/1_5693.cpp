void EchoBay::Reservoir::load_WrLayers(const std::string &folder)
{
    SparseMatrix<floatBO, 0x1> Wr;
    std::string tempName;
    for (int i = 0; i < _nLayers; ++i)
    {
        tempName = folder + "/Wr_eigen" + std::to_string(i) + ".mtx";
        loadMarket(Wr, tempName);
        WrLayers.push_back(Wr);
    }
}