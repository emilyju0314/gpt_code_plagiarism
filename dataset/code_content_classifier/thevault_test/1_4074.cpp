BOOST_FIXTURE_TEST_CASE( configure_and_trigger, server_with_priorities )
    {
        // configure the first characteristics for notifications
        l2cap_input( { 0x12, 0x04, 0x00, 0x01, 0x00 } );
        expected_result( { 0x13 } );

        notify< bluetoe::characteristic_uuid16< 0x8C8B > >();

        BOOST_CHECK_EQUAL(
            connection.client_configurations().flags( notification.client_characteristic_configuration_index() ),
            0x01 );
    }