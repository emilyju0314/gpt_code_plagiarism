int rs_hello_world( rsComm_t*, helloInp_t* _inp, helloOut_t** _out ) {
        rodsLog( LOG_NOTICE, "Dynamic API - HELLO WORLD" );

        ( *_out ) = ( helloOut_t* )malloc( sizeof( helloOut_t ) );
        ( *_out )->_this = 42;
        strncpy( ( *_out )->_that, "hello, world.", 63 );
        ( *_out )->_other._value = 128.0;

        rodsLog( LOG_NOTICE, "Dynamic API - this [%d] that [%s]", _inp->_this, _inp->_that );
        rodsLog( LOG_NOTICE, "Dynamic API - DONE" );

        return 0;
    }