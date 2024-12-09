BOOST_FIXTURE_TEST_CASE( already_the_last_but_one_attribute_gets_clipped, test::request_with_reponse< test::three_apes_service > )
{
    // read the Primary Service, the first and second Characteristic Declaration
    l2cap_input( { 0x0E, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00 } );
    expected_result( {
        0x0F,                                           // opcode
        0xA9, 0x3C, 0xC7, 0x5B, 0xED, 0x4E, 0x8A, 0xA2, // Primary Service
        0x9F, 0x49, 0xE2, 0x0D, 0x94, 0x40, 0x8B, 0x8C,
        0x0A, 0x03, 0x00,                               // first Characteristic Declaration; already clipped
        0xAA, 0x3C, 0xC7
                                                        // second Characteristic...
    } );
}