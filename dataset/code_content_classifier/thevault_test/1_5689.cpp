void EchoBay::Reservoir::init_WinLayers_crj()
{
    // Reset Win
    WinLayers.clear();

    // Determine the input scaling rule
    int countScale = _layerConfig[0].scaleInput.size();//-1;

    // Initialize random engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::bernoulli_distribution probability(0.5);

    // Determine Win sign
    auto opSign = [&](void){return probability(gen) ? 1 : -1;};
    MatrixBO temp = MatrixBO::NullaryExpr(_layerConfig[0].Nr, _Nu, opSign); // Apply value using lambda

    // Homogeneous scaling
    if (countScale == 1)
    {
        WinLayers.push_back(_layerConfig[0].scaleInput[0] * temp);
    }
    else
    {
        // Differentiated input scaling
        MatrixBO Win(_layerConfig[0].Nr, _Nu);
        for (int cols = _Nu - 1; cols >= 0; cols--)
        {
            Win.col(cols) = _layerConfig[0].scaleInput[cols] * temp.col(cols);
        }
        WinLayers.push_back(Win);
    }
    // Fill subsequent layers
    for (int i = 1; i < _nLayers; ++i)
    {
        temp = MatrixBO::NullaryExpr(_layerConfig[i].Nr, _layerConfig[i - 1].Nr + 1, opSign);
        WinLayers.push_back(_layerConfig[i].scaleInput[0] * temp);
    }
}