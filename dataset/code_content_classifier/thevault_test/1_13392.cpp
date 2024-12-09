void TestCLI::testSource(const std::string& dev_name,
                         const std::string& source_name)
{
    IFactory* factory = test::Factory::instance();
    CPPUNIT_ASSERT(factory);

    // we should wait for DB updates before any check
    sleep(db::CHECKDBINTERVAL + 2);

    IDevPtr dev = factory->getResources()->getResourceByName(dev_name);
    CPPUNIT_ASSERT(dev);

    // check actual value
    const std::string dev_source_name =
        Utils::getSourceName(factory, dev->getStringParam(dev::SOURCE));
    CPPUNIT_ASSERT(dev_source_name == source_name);
    // check value at the db
    // IN resource VARCHAR(40),
    // OUT signal_source VARCHAR(40),
    // OUT dvb_type VARCHAR(40),
    // OUT adapter_no TINYINT,
    // OUT frontend_no TINYINT,
    // OUT resource_name VARCHAR(50),
    // OUT return_value INT
    db::Parameters params;
    params.add("@resource", dev->getStringParam(dev::UUID));
    params.add("@signal_source");
    params.add("@dvb_type");
    params.add("@adapter_no");
    params.add("@frontend_no");
    params.add("@resource_name");
    params.add("@return_value");
    db::DB db(factory);
    db.connect();
    db::Result result = db.callSimple(
        "klk_dvb_resource_get",
        params);
    CPPUNIT_ASSERT(result["@return_value"].toInt() == 0);
    // source at the db is equal to current one
    CPPUNIT_ASSERT(result["@signal_source"].toString() ==
                   dev->getStringParam(dev::SOURCE));
}