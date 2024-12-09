TEST_F( EntlUnitTest, EntlAitReceiveUnitTest ) {
    int result ;
    
    result = entl_ait_receive( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}