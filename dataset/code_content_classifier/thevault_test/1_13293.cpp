void TestEncoder::loadModules()
{
    // load adapter first
    // this is necessary because the main module (streamer)
    // is derived from klk::launcher::app::Module that
    // requires adapter to be run in constructor
    loadAdapter();

    // before loading transcode we should setup all
    // klk_app_transcode_test_encoder
    // IN media_type VARCHAR(40)
    db::DB db(klk::test::Factory::instance());
    db.connect();
    db::Parameters params;
    params.add("@media_type", m_media_type);
    db.callSimple("klk_app_transcode_test_encoder", params);
    // now can start it
    CPPUNIT_ASSERT(m_modfactory);
    // now load the transcoder
    m_modfactory->load(MODID);
}