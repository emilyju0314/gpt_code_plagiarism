TEST_F( EntlUnitTest, EntlAitRejectedUnitTest ) {
    int result ;
    
    result = entl_ait_rejected( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}