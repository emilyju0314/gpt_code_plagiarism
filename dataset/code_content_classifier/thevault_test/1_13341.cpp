void DepTest::checkSort()
{
    test::printOut("\nModules dependency test 2 ... ");

    // get sorted list
    /*
     *               t1
     *                |
     *            t2-- ---t3----
     *            |       |    |
     *            t4     t5    t6
     *                         |
     *                         t7
     */
    StringList sorted = m_dep.getSortedList();
    CPPUNIT_ASSERT(sorted.size() == 7);
    StringList result;
    for (StringList::iterator i = sorted.begin(); i != sorted.end(); i++)
    {
        if (*i == "t1")
        {
            CPPUNIT_ASSERT(result.empty());
        }
        else if (*i == "t2")
        {
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t1") !=
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t4") ==
                           result.end());
        }
        else if (*i == "t3")
        {
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t1") !=
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t5") ==
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t6") ==
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t7") ==
                           result.end());
        }
        else if (*i == "t4")
        {
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t2") !=
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t7") ==
                           result.end());
        }
        else if (*i == "t5")
        {
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t3") !=
                           result.end());
        }
        else if (*i == "t6")
        {

            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t3") !=
                           result.end());
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t7") ==
                           result.end());
        }
        else if (*i == "t7")
        {
            CPPUNIT_ASSERT(std::find(result.begin(), result.end(), "t6") !=
                           result.end());
        }
        result.push_back(*i);
    }

    CPPUNIT_ASSERT(sorted == result);
}