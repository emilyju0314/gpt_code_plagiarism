TEST_F( EntlUnitTest, EntlHello2Wait2EntlLoopUnitTest ) {
    int result ;

    result = hello_2_wait_2_entl_loop( &mcn ) ;

    EXPECT_EQ( result, 1 ) ;

}