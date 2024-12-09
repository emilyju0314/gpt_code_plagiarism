int
checkCondInputAccess( genQueryInp_t genQueryInp, int statementNum,
                      icatSessionStruct *icss, int continueFlag ) {
    int i, nCols;
    int userIx = -1, zoneIx = -1, accessIx = -1, dataIx = -1, collIx = -1;
    int status;
    std::string zoneName;

    static char prevDataId[LONG_NAME_LEN];
    static char prevUser[LONG_NAME_LEN];
    static char prevAccess[LONG_NAME_LEN];
    static int prevStatus;

    if ( getValByKey( &genQueryInp.condInput, ADMIN_KW ) ) {
        return 0;
    }

    for ( i = 0; i < genQueryInp.condInput.len; i++ ) {
        if ( strcmp( genQueryInp.condInput.keyWord[i],
                     USER_NAME_CLIENT_KW ) == 0 ) {
            userIx = i;
        }
        if ( strcmp( genQueryInp.condInput.keyWord[i],
                     RODS_ZONE_CLIENT_KW ) == 0 ) {
            zoneIx = i;
        }
        if ( strcmp( genQueryInp.condInput.keyWord[i],
                     ACCESS_PERMISSION_KW ) == 0 ) {
            accessIx = i;
        }
        if ( strcmp( genQueryInp.condInput.keyWord[i],
                     TICKET_KW ) == 0 ) {
            /* for now, log it but the one used is the session ticket */
            rodsLog( LOG_NOTICE, "ticket input, value: %s",
                     genQueryInp.condInput.value[i] );
        }
    }
    if ( genQueryInp.condInput.len == 1 &&
            strcmp( genQueryInp.condInput.keyWord[0], ZONE_KW ) == 0 ) {
        return 0;
    }

    if ( userIx < 0 || zoneIx < 0 || accessIx < 0 ) {
        // this function will get called if any condInput is available.  we now have a
        // case where this kvp is the only option so consider that a success
        char* disable_acl = getValByKey( &genQueryInp.condInput, DISABLE_STRICT_ACL_KW );
        if ( disable_acl ) {
            return 0;
        }
        return CAT_INVALID_ARGUMENT;
    }

    /* Try to find the dataId and/or collID in the output */
    nCols = icss->stmtPtr[statementNum]->numOfCols;
    for ( i = 0; i < nCols; i++ ) {
        if ( strcmp( icss->stmtPtr[statementNum]->resultColName[i], "data_id" ) == 0 ) {
            dataIx = i;
        }
        /* With Oracle the column names are in upper case: */
        if ( strcmp( icss->stmtPtr[statementNum]->resultColName[i], "DATA_ID" ) == 0 ) {
            dataIx = i;
        }
        if ( strcmp( icss->stmtPtr[statementNum]->resultColName[i], "coll_id" ) == 0 ) {
            collIx = i;
        }
        /* With Oracle the column names are in upper case: */
        if ( strcmp( icss->stmtPtr[statementNum]->resultColName[i], "COLL_ID" ) == 0 ) {
            collIx = i;
        }
    }
    if ( dataIx < 0 && collIx < 0 ) {
        return CAT_INVALID_ARGUMENT;
    }

    if ( dataIx >= 0 ) {
        if ( continueFlag == 1 ) {
            if ( strcmp( prevDataId,
                         icss->stmtPtr[statementNum]->resultValue[dataIx] ) == 0 ) {
                if ( strcmp( prevUser, genQueryInp.condInput.value[userIx] ) == 0 ) {
                    if ( strcmp( prevAccess,
                                 genQueryInp.condInput.value[accessIx] ) == 0 ) {
                        return prevStatus;
                    }
                }
            }
        }

        snprintf( prevDataId, sizeof( prevDataId ), "%s", icss->stmtPtr[statementNum]->resultValue[dataIx] );
        snprintf( prevUser, sizeof( prevUser ), "%s", genQueryInp.condInput.value[userIx] );
        snprintf( prevAccess, sizeof( prevAccess ), "%s", genQueryInp.condInput.value[accessIx] );
        prevStatus = 0;

        if ( strlen( genQueryInp.condInput.value[zoneIx] ) == 0 ) {
            if ( !chlGetLocalZone( zoneName ) ) {
            }
        }
        else {
            zoneName = genQueryInp.condInput.value[zoneIx];
        }
        status = cmlCheckDataObjId(
                     icss->stmtPtr[statementNum]->resultValue[dataIx],
                     genQueryInp.condInput.value[userIx],
                     ( char* )zoneName.c_str(),
                     genQueryInp.condInput.value[accessIx],
                     /*                  sessionTicket, accessControlHost, icss); */
                     sessionTicket, sessionClientAddr, icss );
        prevStatus = status;
        return status;
    }

    if ( collIx >= 0 ) {
        if ( strlen( genQueryInp.condInput.value[zoneIx] ) == 0 ) {
            if ( !chlGetLocalZone( zoneName ) ) {
            }
        }
        else {
            zoneName = genQueryInp.condInput.value[zoneIx];
        }
        status = cmlCheckDirId(
                     icss->stmtPtr[statementNum]->resultValue[collIx],
                     genQueryInp.condInput.value[userIx],
                     ( char* )zoneName.c_str(),
                     genQueryInp.condInput.value[accessIx], icss );
    }
    return status;
}