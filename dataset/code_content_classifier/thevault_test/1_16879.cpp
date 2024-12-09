TEST_F( EntlUnitTest, EntlAitSendUnitTest ) {
    int result ;

    result = entl_ait_send( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}