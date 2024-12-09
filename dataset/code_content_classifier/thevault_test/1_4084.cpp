BOOST_FIXTURE_TEST_CASE( connection_update_missing_master_pdu_at_instannce, unconnected )
{
    respond_to( 37, valid_connection_request_pdu );
    add_connection_update_request( 6, 3, 6, 66, 198, 6 );
    add_empty_pdus( *this, 5 );
    add_connection_event_respond_timeout();
    add_empty_pdus( *this, 5 );

    run();

    const auto next        = connection_events().at( 7 );

    // transmitWindowSize   = 7.5ms
    // transmitWindowOffset = 3.75ms
    // connIntervalOLD      = 30ms
    // connIntervalnew      = 7.5ms

    // connIntervalOLD + transmitWindowOffset + connIntervalnew
    bluetoe::link_layer::delta_time window_start( 3750 + 7500 + 30000 );
    // connIntervalOLD + transmitWindowOffset + connIntervalnew + transmitWindowSize
    bluetoe::link_layer::delta_time window_end = window_start + bluetoe::link_layer::delta_time( 7500 );

    window_start -= window_start.ppm( 550 );
    window_end   += window_end.ppm( 550 );

    BOOST_REQUIRE_LT( window_start, window_end );

    BOOST_CHECK_EQUAL( next.start_receive, window_start );
    BOOST_CHECK_EQUAL( next.end_receive, window_end );
}