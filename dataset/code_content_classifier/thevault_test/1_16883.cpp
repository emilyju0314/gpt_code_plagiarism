TEST_F( EntlUnitTest, EntlAloSendUnitTest ) {
    int result ;
    
    result = entl_alo_send( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}