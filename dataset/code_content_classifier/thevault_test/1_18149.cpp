irods::error
readStartupPack(
    irods::network_object_ptr _ptr,
    startupPack_t**     startupPack,
    struct timeval*     tv ) {
    int status;
    msgHeader_t myHeader;
    bytesBuf_t inputStructBBuf, bsBBuf, errorBBuf;
    irods::error ret = readMsgHeader( _ptr, &myHeader, tv );
    if ( !ret.ok() ) {
        return PASS( ret );
    }

    if ( myHeader.msgLen > ( int ) sizeof( startupPack_t ) * 2 ||
            myHeader.msgLen <= 0 ) {
        std::stringstream msg;
        msg << "readStartupPack: problem with myHeader.msgLen = " << myHeader.msgLen;
        return ERROR( SYS_HEADER_READ_LEN_ERR, msg.str() );
    }

    memset( &bsBBuf, 0, sizeof( bytesBuf_t ) );
    ret = readMsgBody(
              _ptr,
              &myHeader,
              &inputStructBBuf,
              &bsBBuf,
              &errorBBuf,
              XML_PROT,
              tv );
    if ( !ret.ok() ) {
        return PASS( ret );
    }

    /* some sanity check */

    if ( strcmp( myHeader.type, RODS_CONNECT_T ) != 0 ) {
        if ( inputStructBBuf.buf != NULL ) {
            clearBBuf( &inputStructBBuf );
        }
        if ( bsBBuf.buf != NULL ) {
            clearBBuf( &bsBBuf );
        }
        if ( errorBBuf.buf != NULL ) {
            clearBBuf( &errorBBuf );
        }
        std::stringstream msg;
        msg << "readStartupPack: wrong mag type - " << myHeader.type << ", expect " << RODS_CONNECT_T;
        return ERROR( SYS_HEADER_TYPE_LEN_ERR, msg.str() );
    }

    if ( myHeader.bsLen != 0 ) {
        if ( bsBBuf.buf != NULL ) {
            clearBBuf( &bsBBuf );
        }
        rodsLog( LOG_NOTICE, "readStartupPack: myHeader.bsLen = %d is not 0",
                 myHeader.bsLen );
    }

    if ( myHeader.errorLen != 0 ) {
        if ( errorBBuf.buf != NULL ) {
            clearBBuf( &errorBBuf );
        }
        rodsLog( LOG_NOTICE,
                 "readStartupPack: myHeader.errorLen = %d is not 0",
                 myHeader.errorLen );
    }

    /* always use XML_PROT for the startup pack */
    status = unpackStruct( inputStructBBuf.buf, ( void ** ) startupPack,
                           "StartupPack_PI", RodsPackTable, XML_PROT );

    clearBBuf( &inputStructBBuf );

    if ( status < 0 ) {
        return ERROR( status, "readStartupPack:unpackStruct error." );
    }

    if ( ( *startupPack )->clientUser[0] != '\0'  &&
            ( *startupPack )->clientRodsZone[0] == '\0' ) {
        /* clientRodsZone is not defined */
        if ( const char* zoneName = getLocalZoneName() ) {
            rstrcpy( ( *startupPack )->clientRodsZone, zoneName, NAME_LEN );
        }
    }
    if ( ( *startupPack )->proxyUser[0] != '\0'  &&
            ( *startupPack )->proxyRodsZone[0] == '\0' ) {
        /* proxyRodsZone is not defined */
        if ( const char* zoneName = getLocalZoneName() ) {
            rstrcpy( ( *startupPack )->proxyRodsZone, zoneName, NAME_LEN );
        }
    }

    return CODE( status );
}