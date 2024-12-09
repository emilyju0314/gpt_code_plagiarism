int
cllOpenEnv( icatSessionStruct *icss ) {
    int             stat;

    OCIEnv           *p_env;
    OCISvcCtx        *p_svc;

    stat = OCIEnvCreate( ( OCIEnv ** )&p_env,
                         ( ub4 )OCI_DEFAULT,
                         ( dvoid * )0, ( dvoid * ( * )( dvoid *, size_t ) )0,
                         ( dvoid * ( * )( dvoid *, dvoid *, size_t ) )0,
                         ( void ( * )( dvoid *, dvoid * ) )0,
                         ( size_t )0, ( dvoid ** )0 );
    if ( stat != OCI_SUCCESS ) {
        rodsLog( LOG_ERROR, "cllOpenEnv: OCIEnvCreate failed" );
        return CAT_ENV_ERR;
    }

    /* Initialize handles */
    stat = OCIHandleAlloc( ( dvoid * ) p_env, ( dvoid ** ) &p_err, OCI_HTYPE_ERROR,
                           ( size_t ) 0, ( dvoid ** ) 0 );

    if ( stat != OCI_SUCCESS ) {
        rodsLog( LOG_ERROR, "cllOpenEnv: OCIHandleAlloc failed" );
        return CAT_ENV_ERR;
    }

    stat = OCIHandleAlloc( ( dvoid * ) p_env, ( dvoid ** ) &p_svc, OCI_HTYPE_SVCCTX,
                           ( size_t ) 0, ( dvoid ** ) 0 );

    if ( stat != OCI_SUCCESS ) {
        rodsLog( LOG_ERROR, "cllOpenEnv: OCIHandleAlloc failed" );
        return CAT_ENV_ERR;
    }

    icss->connectPtr = p_svc;
    icss->environPtr = p_env;

    return 0;
}