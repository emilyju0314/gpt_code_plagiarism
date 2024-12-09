void EchoBay::Reservoir::load_network(const std::string &folder)
{
    // Initialize Win
    this->load_WinLayers(folder);

    // Initialize Wr
    this->load_WrLayers(folder);

    // Initialize stateMat
    this->load_stateMat(folder);
}