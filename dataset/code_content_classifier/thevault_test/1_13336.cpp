void Main::testModulesList(const ModuleList& list)
{
    BOOST_ASSERT(!list.empty());

    // the test selfcheck
    BOOST_ASSERT(
        std::find_if(
            list.begin(), list.end(),
            boost::bind<bool>(FindModuleByID(), _1, "00000")) == list.end()
        );


    // checks that base modules are in the list
    BOOST_ASSERT(
        std::find_if(
            list.begin(), list.end(),
            boost::bind<bool>(FindModuleByID(),
                              _1, klk::msgcore::MODID)) != list.end()
        );
    BOOST_ASSERT(
        std::find_if(
            list.begin(), list.end(),
            boost::bind<bool>(FindModuleByID(),
                              _1, klk::adapter::MODID)) != list.end()
        );
    BOOST_ASSERT(
        std::find_if(
            list.begin(), list.end(),
            boost::bind<bool>(FindModuleByID(),
                              _1, klk::srv::MODID)) != list.end()
        );
}