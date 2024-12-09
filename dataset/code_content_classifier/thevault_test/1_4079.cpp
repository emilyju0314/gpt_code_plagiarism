BOOST_FIXTURE_TEST_CASE( channel_map_request_after_connection_count_wrap, channel_map_request_after_connection_count_wrap_fixture )
{
    end_of_simulation( bluetoe::link_layer::delta_time::seconds( 3000 ) );
    run();

    BOOST_CHECK_EQUAL( connection_events().at( 0x10002 ).channel, 36u );
    BOOST_CHECK_EQUAL( connection_events().at( 0x10003 ).channel, 36u );
    BOOST_CHECK_EQUAL( connection_events().at( 0x10004 ).channel, 36u );
}