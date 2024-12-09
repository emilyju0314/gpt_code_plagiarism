BOOST_AUTO_TEST_CASE( attribute_values )
    {
        // first service
        check_attribute( 0, {
            0x15, 0x08              // 0x0815 service UUID
        } );

        // first characteristic
        check_attribute( 1, {
            0x12,                   // Properties: Read, Notify
            0x52, 0x00,             // Characteristic Value Attribute Handle: 0x0052
            0x16, 0x15              // UUID
        } );
        check_attribute( 2, {
            0x42                    // Value
        } );
        check_attribute( 3, {
            0x00, 0x00              // CCCD
        } );
        check_attribute( 4, {
            'F', 'o', 'o'           // Characteristic User Description
        } );

        // second characteristic
        check_attribute( 5, {
            0x12,                   // Properties: Read, Notify
            0x62, 0x00,             // Characteristic Value Attribute Handle: 0x0062
            0x17, 0x15              // UUID
        } );
        check_attribute( 6, {
            0x43                    // Value
        } );
        check_attribute( 7, {
            0x00, 0x00              // CCCD
        } );
        check_attribute( 8, {
            'B', 'a', 'r'           // Characteristic User Description
        } );
        check_attribute( 9, {
            0x08, 0x15              // User defined descriptor
        } );

        // third characteristic
        check_attribute( 10, {
            0x02,                   // Properties: Read
            0x68, 0x00,             // Characteristic Value Attribute Handle: 0x0068
            0x18, 0x15              // UUID
        } );
        check_attribute( 11, {
            0x44                    // Value
        } );

        // forth characteristic
        check_attribute( 12, {
            0x02,                   // Properties: Read
            0x80, 0x00,             // Characteristic Value Attribute Handle: 0x0070
            0x19, 0x15              // UUID
        } );
        check_attribute( 13, {
            0x45                    // Value
        } );
        check_attribute( 14, {
            'B', 'a', 'z'           // Characteristic User Description
        } );
   }