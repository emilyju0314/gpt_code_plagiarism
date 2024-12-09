void ms2::Spectrum::calcSNR(double snrConf)
{
    double sd = statistics::sd<DataPoint>(_dataPoints, [](const DataPoint& i) -> double{return i.getIntensity();});
    double mean = statistics::mean<DataPoint>(_dataPoints, [](const DataPoint& i) -> double{return i.getIntensity();});
    std::vector<double> stats;
    for(auto point : _dataPoints)
        stats.push_back(abs(point.getIntensity() - mean) / sd);

    auto dist = std::shared_ptr<statistics::ProbabilityDist>();
    size_t len = _dataPoints.size();
    if(len > 30)
        dist = std::make_shared<statistics::NormDist>();
    else dist = std::make_shared<statistics::TDist>(double(len - 1));

    double noise = 0;
    size_t noiseLen = 0;
    for(size_t i = 0; i < len; i++){
        double pVal = dist->pValue(stats[i]);
        if(pVal > snrConf)
            _dataPoints[i].setNoise(false);
        else {
            noise += _dataPoints[i].getIntensity();
            noiseLen++;
        }
    }
    noise /= double(noiseLen);

    for(auto & _dataPoint : _dataPoints)
        _dataPoint.setSNR(_dataPoint.getIntensity() / noise);
}