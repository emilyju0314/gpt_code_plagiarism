int EchoBay::DataStorage::get_nBatches(Eigen::Ref<MatrixBO> samplingData)
{
    int nBatches = (samplingData.col(1).array() == 0).count();
    nBatches = nBatches <= 1 ? nBatches + 1 : nBatches;
    return nBatches;
}