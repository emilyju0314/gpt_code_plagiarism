BOOST_AUTO_TEST_CASE(test_erase_ifs)
{
//BOILERPLATE
    namespace ut=boost::unit_test;
    boost::onullstream    null_output;
    ut::unit_test_log.set_stream(null_output);
    ut::test_suite* test = BOOST_TEST_SUITE("");
//END BOILERPLATE

// CUSTOM CODE
    typedef boost::mpl::list< 
                    std::vector<int>, 
                    std::list<int>, 
                    std::set<int>,
                    std::deque<int>,
                    std::multiset<int>
            > test_types;
            
    typedef boost::mpl::list< 
                    std::map<int, int>, 
                    std::multimap<int, int>
            > test_key_value_types;
    test->add(BOOST_TEST_CASE_TEMPLATE(test_erase_if, test_types));
    test->add(BOOST_TEST_CASE_TEMPLATE(test_key_value_erase_if, test_key_value_types));
// END CUSTOM CODE

//BOILERPLATE
    ut::framework::run(test);
    ut::test_results const& tr = ut::results_collector.results(test->p_id);

    ut::unit_test_log.set_stream(std::cout);
    BOOST_CHECK_EQUAL(tr.p_assertions_failed, (std::size_t)0);
    BOOST_CHECK(!tr.p_aborted);
//END BOILERPLATE
}