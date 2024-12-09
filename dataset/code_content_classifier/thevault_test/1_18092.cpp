int
rsDataObjPhymv( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                transferStat_t **transStat ) {
    int status = 0;
    dataObjInfo_t *dataObjInfoHead = NULL;
    dataObjInfo_t *oldDataObjInfoHead = NULL;
    ruleExecInfo_t rei;
    int multiCopyFlag = 0;
    char *accessPerm = NULL;
    int remoteFlag = 0;
    rodsServerHost_t *rodsServerHost = NULL;
    specCollCache_t *specCollCache = NULL;
    std::string resc_name;

    resolveLinkedPath( rsComm, dataObjInp->objPath, &specCollCache,
                       &dataObjInp->condInput );
    remoteFlag = getAndConnRemoteZone( rsComm, dataObjInp, &rodsServerHost,
                                       REMOTE_OPEN );

    if ( remoteFlag < 0 ) {
        return remoteFlag;
    }
    else if ( remoteFlag == REMOTE_HOST ) {
        status = _rcDataObjPhymv( rodsServerHost->conn, dataObjInp,
                                  transStat );
        return status;
    }

    char* dest_resc = getValByKey( &dataObjInp->condInput, DEST_RESC_NAME_KW );
    if ( dest_resc ) {
        std::string dest_hier; 
        irods::error ret = resolve_hierarchy_for_resc_from_cond_input(
                               rsComm,
                               dest_resc,
                               dest_hier );
        if( !ret.ok() ) {
            irods::log( PASS( ret ) );
            return ret.code();
        }
        addKeyVal(
            &dataObjInp->condInput,
            DEST_RESC_HIER_STR_KW,
            dest_hier.c_str() );
    }

    // =-=-=-=-=-=-=-
    // determine hierarchy string
	char* dest_hier_kw = getValByKey( &dataObjInp->condInput, DEST_RESC_HIER_STR_KW );
    if ( NULL == dest_hier_kw || 0 == strlen(dest_hier_kw) ) {
        std::string       hier;
        irods::error ret = irods::resolve_resource_hierarchy(
		                       irods::CREATE_OPERATION,
							   rsComm,
                               dataObjInp,
							   hier );
        if ( !ret.ok() ) {
            std::stringstream msg;
            msg << __FUNCTION__;
            msg << " :: failed in irods::resolve_resource_hierarchy for [";
            msg << dataObjInp->objPath << "]";
            irods::log( PASSMSG( msg.str(), ret ) );
            return ret.code();
        }

        // =-=-=-=-=-=-=-
        // we resolved the redirect and have a host, set the hier str for subsequent
        // api calls, etc.
        addKeyVal(
		    &dataObjInp->condInput,
			DEST_RESC_HIER_STR_KW,
			hier.c_str() );
    } // if keyword

    char* src_resc = getValByKey( &dataObjInp->condInput, RESC_NAME_KW );
    if ( src_resc ) {
        std::string src_hier; 
        irods::error ret = resolve_hierarchy_for_resc_from_cond_input(
                               rsComm,
                               src_resc,
                               src_hier );
        if( !ret.ok() ) {
            irods::log( PASS( ret ) );
            return ret.code();
        }
        addKeyVal(
            &dataObjInp->condInput,
            RESC_HIER_STR_KW,
            src_hier.c_str() );
    }

    // =-=-=-=-=-=-=-
    // determine hierarchy string
	char* resc_hier_kw = getValByKey( &dataObjInp->condInput, RESC_HIER_STR_KW );
    if ( NULL == resc_hier_kw || 0 == strlen(resc_hier_kw) ) {
        std::string       hier;
        irods::error ret = irods::resolve_resource_hierarchy(
		                       irods::OPEN_OPERATION,
							   rsComm,
                               dataObjInp,
							   hier );
        if ( !ret.ok() ) {
            std::stringstream msg;
            msg << __FUNCTION__;
            msg << " :: failed in irods::resolve_resource_hierarchy for [";
            msg << dataObjInp->objPath << "]";
            irods::log( PASSMSG( msg.str(), ret ) );
            return ret.code();
        }

        // =-=-=-=-=-=-=-
        // we resolved the redirect and have a host, set the hier str for subsequent
        // api calls, etc.
        addKeyVal(
		    &dataObjInp->condInput,
			RESC_HIER_STR_KW,
			hier.c_str() );
    } // if keyword

    *transStat = ( transferStat_t* )malloc( sizeof( transferStat_t ) );
    memset( *transStat, 0, sizeof( transferStat_t ) );

    if( getValByKey( &dataObjInp->condInput, ADMIN_KW ) != NULL ) {
        if ( rsComm->clientUser.authInfo.authFlag < LOCAL_PRIV_USER_AUTH ) {
            return CAT_INSUFFICIENT_PRIVILEGE_LEVEL;
        }
        accessPerm = NULL;
    }
    else {
        accessPerm = ACCESS_DELETE_OBJECT;
    }

    // query rcat for resource info and sort it
    status = getRescForCreate(
	             rsComm,
				 dataObjInp,
				 resc_name );
    if( status < 0 ) {
        return status;
    }
    initReiWithDataObjInp(
	    &rei,
		rsComm,
		dataObjInp );
    status = applyRule(
	             "acSetMultiReplPerResc",
				 NULL,
				 &rei,
				 NO_SAVE_REI );
    if ( strcmp( rei.statusStr, MULTI_COPIES_PER_RESC ) == 0 ) {
        multiCopyFlag = 1;
    }
    else {
        multiCopyFlag = 0;
    }

    // query rcat for dataObjInfo and sort it
    status = getDataObjInfo(
	             rsComm,
				 dataObjInp,
				 &dataObjInfoHead,
                 accessPerm, 1 );

    if ( status < 0 ) {
        rodsLog(
		    LOG_NOTICE,
            "rsDataObjPhymv: getDataObjInfo for %s",
			dataObjInp->objPath );
        return status;
    }

    irods::error ret = test_source_replica_for_write_permissions(
	                       rsComm,
	                       dataObjInfoHead );
	if( !ret.ok() ) {
        irods::log( PASS( ret ) );
		return ret.code();
	}

    status = resolveInfoForPhymv(
	             &dataObjInfoHead,
				 &oldDataObjInfoHead,
				 resc_name,
				 &dataObjInp->condInput,
				 multiCopyFlag );
    if ( status < 0 ) {
        freeAllDataObjInfo( dataObjInfoHead );
        freeAllDataObjInfo( oldDataObjInfoHead );
        if ( status == CAT_NO_ROWS_FOUND ) {
            return 0;
        }
        else {
            return status;
        }
    }
    status = _rsDataObjPhymv(
	             rsComm,
				 dataObjInp,
				 dataObjInfoHead,
				 resc_name.c_str(),
                 *transStat,
				 multiCopyFlag );

    freeAllDataObjInfo( dataObjInfoHead );
    freeAllDataObjInfo( oldDataObjInfoHead );

    return status;
}