BOOST_FIXTURE_TEST_CASE( no_connection_if_supervision_timeout_is_to_small, unconnected )
{
    respond_to(
        37,
        {
            0xc5, 0x22,                         // header
            0x3c, 0x1c, 0x62, 0x92, 0xf0, 0x48, // InitA: 48:f0:92:62:1c:3c (random)
            0x47, 0x11, 0x08, 0x15, 0x0f, 0xc0, // AdvA:  c0:0f:15:08:11:47 (random)
            0x5a, 0xb3, 0x9a, 0xaf,             // Access Address
            0x08, 0x81, 0xf6,                   // CRC Init
            0x03,                               // transmit window size
            0x0b, 0x00,                         // window offset
            0x18, 0x00,                         // interval
            0x05, 0x00,                         // slave latency
            0x23, 0x00,                         // connection timeout 350ms
            0xff, 0xff, 0xff, 0xff, 0x1f,       // used channel map
            0xaa                                // hop increment and sleep clock accuracy
        }
    );

    run();

    check_not_connected( "no_connection_if_supervision_timeout_is_to_small" );
}