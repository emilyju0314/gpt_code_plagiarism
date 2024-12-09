BOOST_FIXTURE_TEST_CASE( channel_map_request_with_one_timeout, channel_map_request_with_one_timeout_fixture )
{
    add_connection_event_respond_timeout(); // event 3
    ll_empty_pdu();
    ll_empty_pdu();                         // event 5; here the map change is applied
    ll_empty_pdu();

    run();

    static constexpr unsigned expected_hop_sequence[] = {
        10, 20, 30, 3, 13, // connection event 0-4
        36, 36
    };

    for ( unsigned i = 0; i != sizeof( expected_hop_sequence ) / sizeof( expected_hop_sequence[ 0 ] ); ++i )
    {
        BOOST_CHECK_EQUAL( connection_events().at( i ).channel, expected_hop_sequence[ i ] );
    }
}