BOOST_FIXTURE_TEST_CASE( start_handle_zero, test::request_with_reponse< test::small_temperature_service > )
{
    static const std::uint8_t start_zero[] = { 0x04, 0x00, 0x00, 0xff, 0xff };

    BOOST_CHECK( check_error_response( start_zero, 0x04, 0x0000, 0x01 ) );
}