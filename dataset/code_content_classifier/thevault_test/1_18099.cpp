int
cmlCheckTicketRestrictions( const char *ticketId, const char *ticketHost,
                            const char *userName, const char *userZone,
                            icatSessionStruct *icss ) {
    int status;
    int stmtNum;
    int hostOK = 0;
    int userOK = 0;
    int groupOK = 0;

    /* first, check if there are any host restrictions, and if so
       return error if the connected client host is not in the list */
    if ( logSQL_CML != 0 ) {
        rodsLog( LOG_SQL, "cmlCheckTicketRestrictions SQL 1" );
    }
    std::vector<std::string> bindVars;
    bindVars.push_back( ticketId );
    status = cmlGetFirstRowFromSqlBV(
                 "select host from R_TICKET_ALLOWED_HOSTS where ticket_id=?",
                 bindVars, &stmtNum, icss );
    if ( status == CAT_NO_ROWS_FOUND ) {
        hostOK = 1;
    }
    else {
        if ( status != 0 ) {
            return status;
        }
    }

    for ( ; status != CAT_NO_ROWS_FOUND; ) {
        if ( strncmp( ticketHost,
                      icss->stmtPtr[stmtNum]->resultValue[0],
                      NAME_LEN ) == 0 ) {
            hostOK = 1;
        }
        status = cmlGetNextRowFromStatement( stmtNum, icss );
        if ( status != 0 && status != CAT_NO_ROWS_FOUND ) {
            return status;
        }
    }
    if ( hostOK == 0 ) {
        return CAT_TICKET_HOST_EXCLUDED;
    }

    /* Now check on user restrictions */
    if ( logSQL_CML != 0 ) {
        rodsLog( LOG_SQL, "cmlCheckTicketRestrictions SQL 2" );
    }
    bindVars.clear();
    bindVars.push_back( ticketId );
    status = cmlGetFirstRowFromSqlBV(
                 "select user_name from R_TICKET_ALLOWED_USERS where ticket_id=?",
                 bindVars,  &stmtNum, icss );
    if ( status == CAT_NO_ROWS_FOUND ) {
        userOK = 1;
    }
    else {
        if ( status != 0 ) {
            return status;
        }
    }
    std::string myUser( userName );
    myUser += "#";
    myUser += userZone;
    for ( ; status != CAT_NO_ROWS_FOUND; ) {
        if ( strncmp( userName,
                      icss->stmtPtr[stmtNum]->resultValue[0],
                      NAME_LEN ) == 0 ) {
            userOK = 1;
        }
        else {
            /* try user#zone */
            if ( strncmp( myUser.c_str(),
                          icss->stmtPtr[stmtNum]->resultValue[0],
                          NAME_LEN ) == 0 ) {
                userOK = 1;
            }
        }
        status = cmlGetNextRowFromStatement( stmtNum, icss );
        if ( status != 0 && status != CAT_NO_ROWS_FOUND ) {
            return status;
        }
    }
    if ( userOK == 0 ) {
        return CAT_TICKET_USER_EXCLUDED;
    }

    /* Now check on group restrictions */
    if ( logSQL_CML != 0 ) {
        rodsLog( LOG_SQL, "cmlCheckTicketRestrictions SQL 3" );
    }
    bindVars.clear();
    bindVars.push_back( ticketId );
    status = cmlGetFirstRowFromSqlBV(
                 "select group_name from R_TICKET_ALLOWED_GROUPS where ticket_id=?",
                 bindVars, &stmtNum, icss );
    if ( status == CAT_NO_ROWS_FOUND ) {
        groupOK = 1;
    }
    else {
        if ( status != 0 ) {
            return status;
        }
    }
    for ( ; status != CAT_NO_ROWS_FOUND; ) {
        int status2;
        status2 = cmlCheckUserInGroup( userName, userZone,
                                       icss->stmtPtr[stmtNum]->resultValue[0],
                                       icss );
        if ( status2 == 0 ) {
            groupOK = 1;
        }
        status = cmlGetNextRowFromStatement( stmtNum, icss );
        if ( status != 0 && status != CAT_NO_ROWS_FOUND ) {
            return status;
        }
    }
    if ( groupOK == 0 ) {
        return CAT_TICKET_GROUP_EXCLUDED;
    }
    return 0;
}