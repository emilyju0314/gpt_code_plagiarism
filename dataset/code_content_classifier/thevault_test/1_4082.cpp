BOOST_FIXTURE_TEST_CASE( connection_update_correct_interval_used, connected_and_valid_connection_update_request )
{
    auto const evt = connection_events()[ 7 ];

    const bluetoe::link_layer::delta_time event_start( 50000 );

    BOOST_CHECK_EQUAL( evt.start_receive, event_start - event_start.ppm( 550 ) );
    BOOST_CHECK_EQUAL( evt.end_receive, event_start + event_start.ppm( 550 ) );
}