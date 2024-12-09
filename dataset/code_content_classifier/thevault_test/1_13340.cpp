void DepTest::checkDep()
{
    test::printOut("\nModules dependency test 1 ... ");

    /*
     *               t1
     *                |
     *            t2-- ---t3----
     *            |       |    |
     *            t4     t5    t6
     *                         |
     *                         t7
     */

    StringList dep1 = m_dep.getDependency("t1");
    CPPUNIT_ASSERT(dep1.size() == 2);
    CPPUNIT_ASSERT(std::find(dep1.begin(), dep1.end(), "t2") != dep1.end());
    CPPUNIT_ASSERT(std::find(dep1.begin(), dep1.end(), "t3") != dep1.end());

    StringList dep2 = m_dep.getDependency("t3");
    CPPUNIT_ASSERT(dep2.size() == 2);
    CPPUNIT_ASSERT(std::find(dep2.begin(), dep2.end(), "t5") != dep2.end());
    CPPUNIT_ASSERT(std::find(dep2.begin(), dep2.end(), "t6") != dep2.end());

    // remove one edge
    m_dep.rmDependency("t3", "t6");
    StringList dep3 = m_dep.getDependency("t3");
    CPPUNIT_ASSERT(dep3.size() == 1);
    CPPUNIT_ASSERT(std::find(dep3.begin(), dep3.end(), "t5") != dep3.end());
    CPPUNIT_ASSERT(std::find(dep3.begin(), dep3.end(), "t6") == dep3.end());
    // restore it
    Result rc = m_dep.addDependency("t3", "t6");
    CPPUNIT_ASSERT(rc == OK);

    // add existent
    rc = m_dep.addDependency("t3", "t5");
    CPPUNIT_ASSERT(rc == OK);
    StringList dep4 = m_dep.getDependency("t3");
    CPPUNIT_ASSERT(dep4.size() == 2);
    CPPUNIT_ASSERT(std::find(dep4.begin(), dep4.end(), "t5") != dep4.end());
    CPPUNIT_ASSERT(std::find(dep4.begin(), dep4.end(), "t6") != dep4.end());

    // add self
    rc = m_dep.addDependency("t3", "t3");
    CPPUNIT_ASSERT(rc == OK);
    StringList dep5 = m_dep.getDependency("t3");
    CPPUNIT_ASSERT(dep5.size() == 2);
    CPPUNIT_ASSERT(std::find(dep5.begin(), dep5.end(), "t5") != dep5.end());
    CPPUNIT_ASSERT(std::find(dep5.begin(), dep5.end(), "t6") != dep5.end());


    // wrong dependency - cicle
    rc = m_dep.addDependency("t7", "t3");
    CPPUNIT_ASSERT(rc == ERROR);

    // ok dep for directed graph
    rc = m_dep.addDependency("t7", "t5");
    CPPUNIT_ASSERT(rc == OK);
    // restore
    m_dep.rmDependency("t7", "t5");
}