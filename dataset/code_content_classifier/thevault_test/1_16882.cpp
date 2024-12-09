TEST_F( EntlUnitTest, EntlAitRejectUnitTest ) {
    int result ;
    
    result = entl_ait_reject( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}