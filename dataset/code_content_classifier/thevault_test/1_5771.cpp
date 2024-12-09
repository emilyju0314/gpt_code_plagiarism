void ms2::Spectrum::removeSNRBelow(double snrThreshold, double snrConf)
{
    calcSNR(snrConf);
    for(auto it = _dataPoints.begin(); it != _dataPoints.end();)
    {
        if(it->getSNR() < snrThreshold)
            _dataPoints.erase(it);
        else ++it;
    }
    updateRanges();
}