const std::string
Utils::getSourceName(IFactory* factory, const std::string& source)
{
    BOOST_ASSERT(factory);

    // `klk_dvb_signal_source_get_name` (
    // IN source VARCHAR(40),
    // OUT name VARCHAR(100),
    // OUT return_value INT
    db::Parameters params;
    params.add("@source", source);
    params.add("@name");
    params.add("@return_value");

    db::DB db(factory);
    db.connect();

    db::Result result = db.callSimple(
        "klk_dvb_signal_source_get_name", params);

    BOOST_ASSERT(result["@return_value"].toInt() == 0);
    return result["@name"].toString();
}