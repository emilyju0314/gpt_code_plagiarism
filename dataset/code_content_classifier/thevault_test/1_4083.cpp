BOOST_FIXTURE_TEST_CASE( connection_update_correct_timeout_used, unconnected )
{
    respond_to( 37, valid_connection_request_pdu );
    add_connection_update_request( 5, 6, 40, 1, 25, 6 );
    add_empty_pdus( *this, 6 );
    add_ll_timeouts( *this, 10 );

    run();

    BOOST_CHECK_EQUAL( connection_events().size(), std::size_t{ 8 + 5 } );
}