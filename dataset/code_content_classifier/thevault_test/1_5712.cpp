int EchoBay::DataStorage::get_maxSamples(const uint8_t type, const int batch) const
{
    auto sumSamples = [](int sum, const ArrayI8 curr) { return sum + curr.count(); };
    int idx = (type == EchoBay::Train) ? 0 : 1;
    auto finalBatch = (batch == -1) ? _samplingBatches[idx].end() : _samplingBatches[idx].begin() + batch;
    int counter = std::accumulate(_samplingBatches[idx].begin(), finalBatch, 0, sumSamples);

    return counter;
}