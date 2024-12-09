uint64_t ts::LNB::intermediateFrequency (uint64_t satellite_frequency) const
{
    if (useHighBand (satellite_frequency)) {
        return satellite_frequency - _high_frequency;
    }
    else if (satellite_frequency < _low_frequency) {
        return _low_frequency - satellite_frequency;
    }
    else {
        return satellite_frequency - _low_frequency;
    }
}