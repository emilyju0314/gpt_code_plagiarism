BOOST_FIXTURE_TEST_CASE( different_attribute_data_size_without_gap, server_with_16bit_characteristics_in_the_middle_100 )
{
    l2cap_input( { 0x10, 0x01, 0x00, 0xff, 0xff, 0x00, 0x28 } );

    static const std::uint8_t expected_result_1[] = {
        0x11, 0x14,                 // response code, size
        0x01, 0x00, 0x03, 0x00,     // handle 0x0001 - 0x0003
        0x2A, 0xD9, 0x91, 0x11,     // service_uuid global_temperature_service
        0xAB, 0x5B, 0x58, 0xB0,
        0x3B, 0x4F, 0x50, 0x44,
        0x52, 0x6E, 0x42, 0xF0,
    };

    BOOST_CHECK_EQUAL_COLLECTIONS( &response[ 0 ], &response[ response_size ], std::begin( expected_result_1 ), std::end( expected_result_1 ) );

    l2cap_input( { 0x10, 0x04, 0x00, 0xff, 0xff, 0x00, 0x28 } );

    static const std::uint8_t expected_result_2[] = {
        0x11, 0x6,                  // response code, size
        0x04, 0x00, 0x08, 0x00,     // handle 0x0004 - 0x000A
        0x16, 0x18                  // Cycling Speed and Cadence
    };

    BOOST_CHECK_EQUAL_COLLECTIONS( &response[ 0 ], &response[ response_size ], std::begin( expected_result_2 ), std::end( expected_result_2 ) );

    l2cap_input( { 0x10, 0x09, 0x00, 0xff, 0xff, 0x00, 0x28 } );

    static const std::uint8_t expected_result_3[] = {
        0x11, 0x14,                 // response code, size
        0x09, 0x00, 0x0F, 0x00,     // handle 0x0001 - 0x0003
        0xA9, 0x3C, 0xC7, 0x5B,     // 128 bit UUID
        0xED, 0x4E, 0x8A, 0xA2,
        0x9F, 0x49, 0xE2, 0x0D,
        0x94, 0x40, 0x8B, 0x8C
    };

    BOOST_CHECK_EQUAL_COLLECTIONS( &response[ 0 ], &response[ response_size ], std::begin( expected_result_3 ), std::end( expected_result_3 ) );

    l2cap_input( { 0x10, 0x10, 0x00, 0xff, 0xff, 0x00, 0x28 } );

    static const std::uint8_t expected_result_4[] = {
        0x01,                       // Error Response
        0x10,                       // request opcode
        0x10, 0x00,                 // request handle
        0x0A                        // «Attribute Not Found»
    };

    BOOST_CHECK_EQUAL_COLLECTIONS( &response[ 0 ], &response[ response_size ], std::begin( expected_result_4 ), std::end( expected_result_4 ) );
}