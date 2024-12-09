BOOST_FIXTURE_TEST_CASE( link_layer_still_active_after_channel_map_request, setup_connect_and_channel_map_request )
{
    ll_control_pdu( { 0x12 } ); // this will be send within the 10th connection event
    ll_empty_pdu();             // the response is expected to this connection event
    run();

    // and the response is send with the 11th event
    BOOST_REQUIRE( !connection_events().at( 10 ).transmitted_data.empty() );
    auto pdu = connection_events().at( 10 ).transmitted_data.front().data;
    BOOST_REQUIRE( !pdu.empty() );
    pdu[ 0 ] &= 0x3;

    static constexpr std::uint8_t expected_response[] = { 0x03, 0x01, 0x13 };
    BOOST_CHECK_EQUAL_COLLECTIONS( std::begin( pdu ), std::end( pdu ), std::begin( expected_response ), std::end( expected_response ) );
}