void ms2::Spectrum::setLabelTop(size_t labelTop)
{
    typedef std::list<ms2::DataPoint*> listType;
    listType pointList;

    for(auto & ion : _dataPoints)
        pointList.push_back(&ion);

    if(pointList.size() > labelTop)
    {
        pointList.sort(ms2::DataPoint::IntComparison());
        pointList.resize(labelTop);
    }

    for(auto & it : pointList)
        it->setTopAbundant(true);
}