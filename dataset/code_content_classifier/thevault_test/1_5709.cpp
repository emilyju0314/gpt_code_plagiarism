ArrayBO EchoBay::update_state(const std::vector<MatrixBO> &WinL,
                              const std::vector<SparseBO> &WrL,
                              const Eigen::Ref<ArrayBO> src, std::vector<ArrayBO> &stateMat,
                              const std::vector<layerParameter> &layerConfig)
{
    // Variables
    int nLayers = WinL.size();
    int i;

    // Leaky state
    // Allocate deep states
    std::vector<ArrayBO> prevState;
    prevState.reserve(nLayers);
    std::vector<ArrayBO> layerInput;
    layerInput.reserve(nLayers - 1); //TODO check if we need to save this
    prevState.push_back(stateMat[0]);
    for (i = 1; i < nLayers; i++)
    {
        prevState.push_back(stateMat[i]);
        ArrayBO inputSupport(stateMat[i - 1].rows() + 1);
        inputSupport << stateMat[i - 1], 1.0;
        layerInput.push_back(inputSupport);
    }

    // Leaky factor
    ArrayBO leakyFactor(nLayers);
    ArrayBO leaky(nLayers);
    i = 0;
    for(const auto& layer: layerConfig)
    {
        leaky[i] = layer.leaky;
        ++i;
    }
    leakyFactor = 1.0 - leaky;

    // update input
    ArrayBO u = ArrayBO::Constant(src.cols() + 1, 1.0);
    size_t uSize = src.cols();
    u.head(uSize) = src;

    // Update leaky state
    prevState[0] = leakyFactor[0] * stateMat[0];

    // Compute new state
    stateMat[0] = WinL[0] * u.matrix() + WrL[0] * stateMat[0].matrix();
    stateMat[0] = prevState[0] + leaky[0] * stateMat[0].tanh();
    for (i = 1; i < nLayers; ++i)
    {
        // Update leaky state
        prevState[i] = leakyFactor[i] * stateMat[i];
        layerInput[i - 1] << stateMat[i - 1], 1.0;

        // Compute new state
        stateMat[i] = WinL[i] * layerInput[i - 1].matrix() + WrL[i] * stateMat[i].matrix();
        stateMat[i] = prevState[i] + leaky[i] * stateMat[i].tanh();
    }

    // Return final state TODO decide how to manage this in DeepESN
    return stateMat[nLayers - 1];
}