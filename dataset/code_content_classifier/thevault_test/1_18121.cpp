int
genqAppendAccessCheck() {
    int doCheck = 0;
    int addedTicketCheck = 0;

    if ( accessControlPriv == LOCAL_PRIV_USER_AUTH ) {
        return 0;
    }

    if ( accessControlControlFlag > 1 ) {
        doCheck = 1;
    }

    if ( doCheck == 0 ) {
        if ( strncmp( accessControlUserName, ANONYMOUS_USER, MAX_NAME_LEN ) == 0 ) {
            doCheck = 1;
        }
    }

    if ( cllBindVarCount + 6 >= MAX_BIND_VARS ) {
        /* too close, should normally have plenty of slots */
        return CAT_BIND_VARIABLE_LIMIT_EXCEEDED;
    }

    /* First, in all cases (non-admin), check on ticket_string
       and, if present, restrict to the owner */
    if ( strstr( selectSQL, "ticket_string" ) != NULL &&
            strstr( selectSQL, "R_TICKET_MAIN" ) != NULL ) {
        if ( strlen( whereSQL ) > 6 ) {
            if ( !rstrcat( whereSQL, " AND ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
        cllBindVars[cllBindVarCount++] = accessControlUserName;
        cllBindVars[cllBindVarCount++] = accessControlZone;
        if ( !rstrcat( whereSQL, "R_TICKET_MAIN.user_id in (select user_id from R_USER_MAIN UM where UM.user_name = ? AND UM.zone_name=?)", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    }

    if ( doCheck == 0 ) {
        return 0;
    }

    /* if an item in R_DATA_MAIN is being accessed, add a
       (complicated) addition to the where clause to check access */
    if ( strstr( selectSQL, "R_DATA_MAIN" ) != NULL ||
            strstr( whereSQL, "R_DATA_MAIN" ) != NULL ) {

        if ( strlen( whereSQL ) > 6 ) {
            if ( !rstrcat( whereSQL, " AND ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
        if ( sessionTicket[0] == '\0' ) {
            /* Normal access control */

            cllBindVars[cllBindVarCount++] = accessControlUserName;
            cllBindVars[cllBindVarCount++] = accessControlZone;
            if ( !rstrcat( whereSQL, "R_DATA_MAIN.data_id in (select object_id from R_OBJT_ACCESS OA, R_USER_GROUP UG, R_USER_MAIN UM, R_TOKN_MAIN TM where UM.user_name=? and UM.zone_name=? and UM.user_type_name!='rodsgroup' and UM.user_id = UG.user_id and UG.group_user_id = OA.user_id and OA.object_id = R_DATA_MAIN.data_id and OA.access_type_id >= TM.token_id and  TM.token_namespace ='access_type' and TM.token_name = 'read object')", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
        else {
            /* Ticket-based access control */
            cllBindVars[cllBindVarCount++] = sessionTicket;
            cllBindVars[cllBindVarCount++] = sessionTicket;
            if ( !rstrcat( whereSQL, "( R_DATA_MAIN.data_id in (select object_id from R_TICKET_MAIN TICK where TICK.ticket_string=?) OR R_COLL_MAIN.coll_id in (select object_id from R_TICKET_MAIN TICK where TICK.ticket_string=?))", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
            addedTicketCheck = 1;
        }
    }

    /* if an item in R_COLL_MAIN is being accessed, add a
       (complicated) addition to the where clause to check access */
    if ( strstr( selectSQL, "R_COLL_MAIN" ) != NULL ||
            strstr( whereSQL, "R_COLL_MAIN" ) != NULL ) {
        if ( sessionTicket[0] == '\0' ) {
            /* Normal access control */
            if ( strlen( whereSQL ) > 6 ) {
                if ( !rstrcat( whereSQL, " AND ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
            }
            cllBindVars[cllBindVarCount++] = accessControlUserName;
            cllBindVars[cllBindVarCount++] = accessControlZone;
            if ( !rstrcat( whereSQL, "R_COLL_MAIN.coll_id in (select object_id from R_OBJT_ACCESS OA, R_USER_GROUP UG, R_USER_MAIN UM, R_TOKN_MAIN TM where UM.user_name=? and UM.zone_name=? and UM.user_type_name!='rodsgroup' and UM.user_id = UG.user_id and OA.object_id = R_COLL_MAIN.coll_id and UG.group_user_id = OA.user_id and OA.access_type_id >= TM.token_id and  TM.token_namespace ='access_type' and TM.token_name = 'read object')", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
        else {
            /* Ticket-based access control */
            /* We add this unless we already added the SQL check a few
              lines above that includes this */
            if ( addedTicketCheck != 1 ) {
                if ( strlen( whereSQL ) > 6 ) {
                    if ( !rstrcat( whereSQL, " AND ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
                }
                cllBindVars[cllBindVarCount++] = sessionTicket;
                if ( strstr( whereSQL, "parent_coll_name =" ) != NULL ) {
                    /*
                      If the where clause is checking on the parent
                      collection, assume that the needed ticket check is on
                      the parent.  This works for the 'ils' queries so that
                      a read (or write) ticket on a collection will find the
                      existing sub-collections.
                      */
                    if ( !rstrcat( whereSQL, "parent_coll_name IN (select coll_name from R_COLL_MAIN where coll_id in (select object_id from R_TICKET_MAIN TICK where TICK.ticket_string=?))", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
                }
                else {
                    if ( !rstrcat( whereSQL, "R_COLL_MAIN.coll_id in (select object_id from R_TICKET_MAIN TICK where TICK.ticket_string=?)", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
                }
            }
        }
    }
    return 0;
}