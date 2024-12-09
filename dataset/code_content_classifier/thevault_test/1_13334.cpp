void Main::testModules()
{
    printOut("\nModules test ...");

    // tests that all modules can be loaded
    IModuleFactory* factory = test::Factory::instance()->getModuleFactory();
    // will produce exception in the case of error
    printOut("\n\tklk::IModuleFactory::getModules() ...");
    ModuleList list1 = factory->getModules();
    testModulesList(list1);
    printOut("\n\tklk::IModuleFactory::getModulesWithoutRegistration() ...");
    ModuleList list2 = factory->getModulesWithoutRegistration();
    testModulesList(list2);
}