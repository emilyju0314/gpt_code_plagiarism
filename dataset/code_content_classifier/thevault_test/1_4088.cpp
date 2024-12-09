BOOST_FIXTURE_TEST_CASE( start_handle_larger_than_ending, test::request_with_reponse< test::small_temperature_service > )
{
    static const std::uint8_t larger_than[] = { 0x04, 0x06, 0x00, 0x05, 0x00 };

    BOOST_CHECK( check_error_response( larger_than, 0x04, 0x0006, 0x01 ) );
}