BOOST_FIXTURE_TEST_CASE( channel_map_request, connect_and_channel_map_request )
{
    static constexpr unsigned expected_hop_sequence[] = {
        10, 20, 30, 3, 13, 23, // connection event 0-5
        28, 6
    };

    for ( unsigned i = 0; i != sizeof( expected_hop_sequence ) / sizeof( expected_hop_sequence[ 0 ] ); ++i )
    {
        BOOST_CHECK_EQUAL( connection_events().at( i ).channel, expected_hop_sequence[ i ] );
    }
}