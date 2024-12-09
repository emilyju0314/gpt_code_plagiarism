void EchoBay::Reservoir::init_network()
{
    // Initialize Win
    switch(_type)
    {
        case 0: this->init_WinLayers();
                break;
        case 1: this->init_WinLayers_swt();
                break;
        case 2: this->init_WinLayers_crj();
                break;
    }

    // Initialize Wr
    this->init_WrLayers();

    // Initialize stateMat
    this->init_stateMat();
}