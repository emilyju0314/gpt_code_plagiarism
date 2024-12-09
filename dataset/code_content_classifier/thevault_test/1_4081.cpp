BOOST_FIXTURE_TEST_CASE( connection_update_correct_transmit_window, connected_and_valid_connection_update_request )
{
    auto const evt = connection_events()[ 6 ];

    bluetoe::link_layer::delta_time window_start( 30000 + 7500 );
    bluetoe::link_layer::delta_time window_end( 30000 + 7500 + 6250 );
    window_start -= window_start.ppm( 550 );
    window_end   += window_end.ppm( 550 );

    BOOST_REQUIRE_LT( window_start, window_end );

    BOOST_CHECK_EQUAL( evt.start_receive, window_start );
    BOOST_CHECK_EQUAL( evt.end_receive, window_end );
}