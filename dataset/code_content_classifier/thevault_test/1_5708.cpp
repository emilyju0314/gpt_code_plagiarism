void EchoBay::compute_state(Eigen::Ref<MatrixBO> dst, const std::vector<MatrixBO> &WinL,
                           const std::vector<SparseBO> &WrL,
                           const MatrixBO &src, std::vector<ArrayBO> &stateMat,
                           const Eigen::Ref<const ArrayI8> sampleState,
                           const std::vector<layerParameter> &layerConfig)
{
    // Variables
    size_t trainSamples = src.rows();
    MatrixBO u(src.cols()+1, src.rows());
    u << src.transpose(), MatrixBO::Ones(1, src.rows()); // TODO improve this to avoid transpose
    int nLayers = WinL.size();
    int sample = 0;
    int i;

    // Leaky state
    // Allocate deep states
    std::vector<ArrayBO> prevState;
    prevState.reserve(nLayers);
    std::vector<ArrayBO> layerInput;
    layerInput.reserve(nLayers - 1);
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

    // Computation
    for (size_t t = 0; t < trainSamples; ++t)
    {
        // Update leaky state
        prevState[0] = leakyFactor[0] * stateMat[0];

        // Compute new state
        stateMat[0] = WinL[0] * u.col(t) + WrL[0] * stateMat[0].matrix();
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
        // Save state for later usage
        if (sampleState(t) != 0)
        {
            int j = 0;
            for(const auto& state: stateMat)
            {
                dst.row(sample).segment(j, state.size()) = state.transpose();
                j += state.size();
            }
            dst.row(sample).tail(1) << 1.0;
            sample++;
            if (sampleState(t) == -1)
            {
                for (auto& state : stateMat)
                {
                    state.setZero();
                }
            }
        }
    }
}