MatrixBO EchoBay::DataStorage::get_data(const uint8_t type, const uint8_t select) const
{
    uint8_t _type = (type == EchoBay::Train) ? 0 : 1; // Avoid bad calls
    return (select == EchoBay::selData) ? _seriesData[_type] : _seriesLabel[_type];
}