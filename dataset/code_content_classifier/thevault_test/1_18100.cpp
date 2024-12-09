int checkObjIdByTicket( const char *dataId, const char *accessLevel,
                        const char *ticketStr, const char *ticketHost,
                        const char *userName, const char *userZone,
                        icatSessionStruct *icss ) {
    int status, i;
    char *cVal[10];
    int iVal[10];
    char ticketId[NAME_LEN] = "";
    char usesCount[NAME_LEN] = "";
    char usesLimit[NAME_LEN] = "";
    char ticketExpiry[NAME_LEN] = "";
    char restrictions[NAME_LEN] = "";
    char writeFileCount[NAME_LEN] = "";
    char writeFileLimit[NAME_LEN] = "";
    char writeByteCount[NAME_LEN] = "";
    char writeByteLimit[NAME_LEN] = "";
    int iUsesCount = 0;
    int iUsesLimit = 0;
    int iWriteFileCount = 0;
    int iWriteFileLimit = 0;
    int iWriteByteCount = 0;
    int iWriteByteLimit = 0;
    char myUsesCount[NAME_LEN];
    char myWriteFileCount[NAME_LEN];
    rodsLong_t intDataId;
    static rodsLong_t previousDataId1 = 0;
    static rodsLong_t previousDataId2 = 0;

    static char prevTicketId[50] = "";

    for ( i = 0; i < 10; i++ ) {
        iVal[i] = NAME_LEN;
    }

    cVal[0] = ticketId;
    cVal[1] = usesLimit;
    cVal[2] = usesCount;
    cVal[3] = ticketExpiry;
    cVal[4] = restrictions;
    if ( strncmp( accessLevel, "modify", 6 ) == 0 ) {
        if ( logSQL_CML != 0 ) {
            rodsLog( LOG_SQL, "checkObjIdByTicket SQL 1 " );
        }
        /* ticket must also be of type 'write', and get the
            writeFileCount and writeFileLimit  */
        cVal[5] = writeFileCount;
        cVal[6] = writeFileLimit;
        cVal[7] = writeByteCount;
        cVal[8] = writeByteLimit;
        std::vector<std::string> bindVars;
        bindVars.push_back( ticketStr );
        bindVars.push_back( dataId );
        bindVars.push_back( dataId );
        status = cmlGetStringValuesFromSql(
                     "select ticket_id, uses_limit, uses_count, ticket_expiry_ts, restrictions, write_file_count, write_file_limit, write_byte_count, write_byte_limit from R_TICKET_MAIN where ticket_type = 'write' and ticket_string = ? and (object_id = ? or object_id in (select coll_id from R_DATA_MAIN where data_id = ?))",
                     cVal, iVal, 9, bindVars, icss );

    }
    else {
        /* don't check ticket type, 'read' or 'write' is fine */
        if ( logSQL_CML != 0 ) {
            rodsLog( LOG_SQL, "checkObjIdByTicket SQL 2 " );
        }
        std::vector<std::string> bindVars;
        bindVars.push_back( ticketStr );
        bindVars.push_back( dataId );
        bindVars.push_back( dataId );
        status = cmlGetStringValuesFromSql(
                     "select ticket_id, uses_limit, uses_count, ticket_expiry_ts, restrictions from R_TICKET_MAIN where ticket_string = ? and (object_id = ? or object_id in (select coll_id from R_DATA_MAIN where data_id = ?))",
                     cVal, iVal, 5, bindVars, icss );
    }

    if ( status != 0 ) {
        return CAT_TICKET_INVALID;
    }

    if ( strncmp( ticketId, prevTicketId, sizeof( prevTicketId ) ) != 0 ) {
        snprintf( prevTicketId, sizeof( prevTicketId ), "%s", ticketId );
        status = cmlAudit3( AU_USE_TICKET, ticketId, userName, userZone,
                            ticketStr, icss );
        if ( status != 0 ) {
            return status;
        }
    }

    if ( ticketExpiry[0] != '\0' ) {
        rodsLong_t ticketExp, now;
        char myTime[50];

        ticketExp = atoll( ticketExpiry );
        if ( ticketExp > 0 ) {
            getNowStr( myTime );
            now = atoll( myTime );
            if ( now > ticketExp ) {
                return CAT_TICKET_EXPIRED;
            }
        }
    }

    status = cmlCheckTicketRestrictions( ticketId, ticketHost,
                                         userName, userZone, icss );
    if ( status != 0 ) {
        return status;
    }

    if ( strncmp( accessLevel, "modify", 6 ) == 0 ) {
        iWriteByteLimit = atoi( writeByteLimit );
        if ( iWriteByteLimit > 0 ) {
            iWriteByteCount = atoi( writeByteCount );
            if ( iWriteByteCount > iWriteByteLimit ) {
                return CAT_TICKET_WRITE_BYTES_EXCEEDED;
            }
        }

        iWriteFileLimit = atoi( writeFileLimit );
        if ( iWriteFileLimit > 0 ) {
            iWriteFileCount = atoi( writeFileCount );
            if ( iWriteFileCount > iWriteFileLimit ) {
                return CAT_TICKET_WRITE_USES_EXCEEDED;
            }
            intDataId = atoll( dataId );
            /* Don't update a second time if this id matches the last one */
            if ( previousDataId1 != intDataId ) {
                iWriteFileCount++;
                snprintf( myWriteFileCount, sizeof myWriteFileCount, "%d",
                          iWriteFileCount );
                cllBindVars[cllBindVarCount++] = myWriteFileCount;
                cllBindVars[cllBindVarCount++] = ticketId;
                if ( logSQL_CML != 0 ) {
                    rodsLog( LOG_SQL, "checkObjIdByTicket SQL 3 " );
                }
                status =  cmlExecuteNoAnswerSql(
                              "update R_TICKET_MAIN set write_file_count=? where ticket_id=?",
                              icss );
                if ( status != 0 ) {
                    return status;
                }
#ifndef ORA_ICAT
                /* as with auditing, do a commit on disconnect if needed */
                cllCheckPending( "", 2, icss->databaseType );
#endif
            }
            previousDataId1 = intDataId;
        }
    }

    iUsesLimit = atoi( usesLimit );
    if ( iUsesLimit > 0 ) {
        iUsesCount = atoi( usesCount );
        if ( iUsesCount > iUsesLimit ) {
            return CAT_TICKET_USES_EXCEEDED;
        }
        intDataId = atoll( dataId );
        /* Don't update a second time if this id matches the last one */
        if ( previousDataId2 != intDataId ) {
            iUsesCount++;
            snprintf( myUsesCount, sizeof myUsesCount, "%d", iUsesCount );
            cllBindVars[cllBindVarCount++] = myUsesCount;
            cllBindVars[cllBindVarCount++] = ticketId;
            if ( logSQL_CML != 0 ) {
                rodsLog( LOG_SQL, "checkObjIdByTicket SQL 4 " );
            }
            status =  cmlExecuteNoAnswerSql(
                          "update R_TICKET_MAIN set uses_count=? where ticket_id=?", icss );
            if ( status != 0 ) {
                return status;
            }
#ifndef ORA_ICAT
            /* as with auditing, do a commit on disconnect if needed*/
            cllCheckPending( "", 2, icss->databaseType );
#endif
        }
        previousDataId2 = intDataId;
    }
    return 0;
}