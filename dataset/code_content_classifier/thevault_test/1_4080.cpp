BOOST_FIXTURE_TEST_CASE( connection_update_in_the_past, unconnected )
{
    respond_to( 37, valid_connection_request_pdu );
    add_connection_update_request( 5, 5, 40, 1, 200, 0x8002 );
    add_empty_pdus( *this, 5 );

    run();

    BOOST_CHECK_EQUAL( connection_events().size(), 1u );
}