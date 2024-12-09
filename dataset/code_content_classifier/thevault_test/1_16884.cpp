TEST_F( EntlUnitTest, EntlAloReceiveUnitTest ) {
    int result ;
    
    result = entl_alo_receive( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}