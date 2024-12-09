void ms2::Spectrum::setMZRange(double minMZ, double maxMZ, bool _sort)
{
    //sort ions by mz
    if(_sort)
        sort(_dataPoints.begin(), _dataPoints.end(), DataPoint::MZComparison());

    auto begin = _dataPoints.begin();
    auto end = _dataPoints.end();

    //find min mz
    for(auto it = _dataPoints.begin(); it != _dataPoints.end(); ++it)
    {
        if(it->getMZ() <= minMZ)
        {
            begin = it;
            continue;
        }
        else break;
    }
    //find max mz
    for(auto it = begin; it != _dataPoints.end(); ++it)
    {
        if(it->getMZ() < maxMZ)
        {
            end = it;
            continue;
        }
        else break;
    }

    _dataPoints = ionVecType(begin, end);
    updateRanges();
}