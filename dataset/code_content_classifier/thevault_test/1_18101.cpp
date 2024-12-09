int cmlCheckDataObjId( const char *dataId, const char *userName,  const char *zoneName,
                       const char *accessLevel, const char *ticketStr, const char *ticketHost,
                       icatSessionStruct *icss ) {
    int status;
    rodsLong_t iVal;

    iVal = 0;
    if ( ticketStr != NULL && *ticketStr != '\0' ) {
        status = checkObjIdByTicket( dataId, accessLevel, ticketStr,
                                     ticketHost, userName, zoneName,
                                     icss );
        if ( status != 0 ) {
            return status;
        }
    }
    else {
        if ( logSQL_CML != 0 ) {
            rodsLog( LOG_SQL, "cmlCheckDataObjId SQL 1 " );
        }
        std::vector<std::string> bindVars;
        bindVars.push_back( dataId );
        bindVars.push_back( userName );
        bindVars.push_back( zoneName );
        bindVars.push_back( accessLevel );
        status = cmlGetIntegerValueFromSql(
                     "select object_id from R_OBJT_ACCESS OA, R_DATA_MAIN DM, R_USER_GROUP UG, R_USER_MAIN UM, R_TOKN_MAIN TM where OA.object_id=? and UM.user_name=? and UM.zone_name=? and UM.user_type_name!='rodsgroup' and UM.user_id = UG.user_id and OA.object_id = DM.data_id and UG.group_user_id = OA.user_id and OA.access_type_id >= TM.token_id and  TM.token_namespace ='access_type' and TM.token_name = ?",
                     &iVal,
                     bindVars,
                     icss );
        if ( iVal == 0 ) {
            return CAT_NO_ACCESS_PERMISSION;
        }
    }
    if ( status != 0 ) {
        return CAT_NO_ACCESS_PERMISSION;
    }
    cmlAudit2( AU_ACCESS_GRANTED, dataId, userName, zoneName, accessLevel, icss );
    return status;
}