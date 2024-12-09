void EchoBay::Reservoir::print_params(const int nLayers, const int nWashout, const double lambda)
{
    //std::cout << "\n";
#ifdef USE_TBB
    cout_mutex.lock();
#endif
    std::cout << "Nr" << std::string(14, ' ');

    // Switch topology
    switch(_type)
    {
        case 0: std::cout << "density" << std::string(9, ' ');
                break;
        case 1: std::cout << "edges" << std::string(11, ' ');
                break;
        case 2: std::cout << "jump" << std::string(12, ' ');
                break;
    }
    std::cout << "scaleInput" << std::string(8 * (_layerConfig[0].scaleInput.size() - 1) + 1, ' ')
              << "leaky" << std::string(11, ' ')
              << "rho" << std::endl;
    
    int active_units = 0;
    for (int i = 0; i < nLayers; i++)
    {
        std::cout << std::setprecision(5)
                  << std::fixed << _layerConfig[i].Nr << "\t\t";

        // Switch topology
        if(_type == 0)
        {
            std::cout << std::fixed << _layerConfig[i].density << "\t\t";
        }
        else
        {
            std::cout << std::fixed << _layerConfig[i].edgesJumps << "\t\t";
        }

        // Sum active_units ATTENTION the network must be configured before print_params
        active_units += WrLayers[i].nonZeros();

        for (size_t countScale = 0; countScale < _layerConfig[i].scaleInput.size(); countScale++)
        {
            std::cout << std::fixed << _layerConfig[i].scaleInput[countScale] << " ";
        }
        std::cout << std::string(8 * (i != 0) * (_layerConfig[0].scaleInput.size() - 1) + 3, ' ');
        std::cout << std::fixed << _layerConfig[i].leaky << std::string(9, ' ')
                  << std::fixed << _layerConfig[i].desiredRho
                  << std::endl;
    }
    // Print general values
    std::cout << "washout\t" << nWashout << std::endl;
    std::cout << "lambda\t" << lambda << std::endl;
    std::cout << "active units\t" << active_units << std::endl;
#ifdef USE_TBB
    cout_mutex.unlock();
#endif
}