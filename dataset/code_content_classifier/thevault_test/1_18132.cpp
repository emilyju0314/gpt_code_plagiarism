int
logOraError( int level, OCIError *errhp, sword status ) {
    sb4 errcode;
    int errorVal = -1;
    if ( status == OCI_SUCCESS ) {
        return 0;
    }
    switch ( status )  {
    case OCI_SUCCESS_WITH_INFO:
        rodsLog( level, "OCI_SUCCESS_WITH_INFO" );
        OCIErrorGet( ( dvoid * ) errhp, ( ub4 ) 1, ( text * ) NULL, &errcode,
                     oraErrorMsg, ( ub4 ) sizeof( oraErrorMsg ),
                     ( ub4 ) OCI_HTYPE_ERROR );
        rodsLog( level, "Error - %s\n", oraErrorMsg );
        errorVal = 0;
        break;
    case OCI_NEED_DATA:
        rodsLog( level, "OCI_NEED_DATA" );
        break;
    case OCI_NO_DATA:
        rodsLog( level, "OCI_NO_DATA" );
        errorVal = 0;
        break;
    case OCI_ERROR:
        OCIErrorGet( ( dvoid * ) errhp, ( ub4 ) 1, ( text * ) NULL, &errcode,
                     oraErrorMsg, ( ub4 ) sizeof( oraErrorMsg ),
                     ( ub4 ) OCI_HTYPE_ERROR );
        rodsLog( level, "OCI_Error: %s", oraErrorMsg );
        if ( strstr( ( char * )oraErrorMsg, "unique constraint" ) != 0 ) {
            errorVal =  CATALOG_ALREADY_HAS_ITEM_BY_THAT_NAME;
        }
        break;
    case OCI_INVALID_HANDLE:
        rodsLog( level, "OCI_INVALID_HANDLE\n" );
        break;
    case OCI_STILL_EXECUTING:
        rodsLog( level, "OCI_STILL_EXECUTING\n" );
        break;
    case OCI_CONTINUE:
        rodsLog( level, "OCI_CONTINUE\n" );
        break;
    default:
        rodsLog( level, "Unknown OCI status - %d", status );
        break;
    }
    return errorVal;
}