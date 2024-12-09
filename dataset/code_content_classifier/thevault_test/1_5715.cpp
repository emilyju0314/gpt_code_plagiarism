ArrayI8 EchoBay::DataStorage::set_sampleArray(Eigen::Ref<MatrixBO> samplingData, int nWashout, bool init_flag, const std::string &problemType, const std::string &fitnessFunction, const uint8_t type)
{
    int nBatches = get_nBatches(samplingData);
    // Generate sampling vectors
    ArrayI resetSamples(samplingData.rows());
    // Index that controls activity on training vector or validation vector
    int arrIdx = (int)type; //(type == "train") ? 0 : 1;
    // Clear old vectors TODO this should be improved
    _samplingBatches[arrIdx].clear();
    _samplingBatches[arrIdx].reserve(nBatches);
    _dataOffset[arrIdx].clear();
    _dataOffset[arrIdx].reserve(nBatches);

    ArrayI8 samplingPoints;

    // Get cumulative sum and differences
    auto sumIntCast = [](floatBO x, floatBO y) { return (int)(x + y); };
    std::partial_sum(samplingData.col(0).data(), samplingData.col(0).data() + samplingData.col(0).size(), resetSamples.data(), sumIntCast);

    // Place 1 to sample data
    samplingPoints = init_array(resetSamples.tail(1)[0], problemType, fitnessFunction);
    // TODO Check washout size
    // if(nWashout >= SamplingTrain.col(0).minCoeff() || nWashout >= SamplingVal.col(0).minCoeff())
    // {
    //     std::cout << "Washout is oversize with respect to smallest data window" << std::endl;
    //     throw std::exception();
    // }
    if (nBatches == 1)
    {
        int nSamples = _seriesData[type].rows();
        ArrayI8 support = init_array(nSamples, problemType, fitnessFunction);
        // Add washout
        if (nWashout > 0 && init_flag)
        {
            support.head(nWashout) << ArrayI8::Zero(nWashout);
        }
        // Push to sampler
        _samplingBatches[arrIdx].push_back(support);
        _dataOffset[arrIdx].push_back(0);
    }
    else
    {
        int lastReset = 0;
        std::vector<Eigen::Index> idxSupport;
        for (int s = 0; s < resetSamples.rows(); s++)
        {
            if ((samplingData(s, 1) == 0) | (s == resetSamples.rows() - 1))
            {
                ArrayI8 support = init_array(resetSamples[s] - lastReset, problemType, fitnessFunction);
                // Annotate last reset
                lastReset = resetSamples[s];
                // Add washout
                if (nWashout > 0)
                {
                    support.head(nWashout) << ArrayI8::Zero(nWashout);
                }
                // Add partial samples
                for (const auto &sample : idxSupport)
                {
                    support[sample] = 1;
                }
                idxSupport.clear();
                // Add reset
                support.tail(1) << -1;
                // Push back data offset
                if (_samplingBatches[arrIdx].size() < 1)
                {
                    _dataOffset[arrIdx].push_back(0);
                }
                else
                {
                    _dataOffset[arrIdx].push_back(_dataOffset[arrIdx].back() + _samplingBatches[arrIdx].back().rows());
                }
                // Push to sampler
                _samplingBatches[arrIdx].push_back(support);
            }
            else if (samplingData(s, 1) == 1)
            {
                // Accumulate samples an then assign them at the next reset
                int idx = resetSamples[s] > 0 ? resetSamples[s] - 1 : resetSamples[s];
                idxSupport.push_back(idx - lastReset);
            }
        }
    }

    // Initial washout
    // Keep in consideration if reset was triggered at the end of TrainingSet
    // TODO this should be not necessary now
    if (init_flag)
    {
        samplingPoints.block(0, 0, nWashout, 1) = ArrayI8::Constant(nWashout, 0);
    }
    int startSample = 0;
    for (const auto &batch : _samplingBatches[arrIdx])
    {
        samplingPoints.block(startSample, 0, batch.rows(), 1) << batch;
        startSample += batch.rows();
    }
    _samplingFull[type] = samplingPoints;

    return samplingPoints;
}