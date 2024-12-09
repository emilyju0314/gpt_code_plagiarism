rodsLong_t
cmlCheckResc( const char *rescName, const char *userName, const char *userZone, const char *accessLevel,
              icatSessionStruct *icss ) {
    int status;
    rodsLong_t iVal;

    if ( logSQL_CML != 0 ) {
        rodsLog( LOG_SQL, "cmlCheckResc SQL 1 " );
    }

    std::vector<std::string> bindVars;
    bindVars.push_back( rescName );
    bindVars.push_back( userName );
    bindVars.push_back( userZone );
    bindVars.push_back( accessLevel );
    status = cmlGetIntegerValueFromSql(
                 "select resc_id from R_RESC_MAIN RM, R_OBJT_ACCESS OA, R_USER_GROUP UG, R_USER_MAIN UM, R_TOKN_MAIN TM where RM.resc_name=? and UM.user_name=? and UM.zone_name=? and UM.user_type_name!='rodsgroup' and UM.user_id = UG.user_id and OA.object_id = RM.resc_id and UG.group_user_id = OA.user_id and OA.access_type_id >= TM.token_id and  TM.token_namespace ='access_type' and TM.token_name = ?",
                 &iVal, bindVars, icss );
    if ( status ) {
        /* There was an error, so do another sql to see which
           of the two likely cases is problem. */

        if ( logSQL_CML != 0 ) {
            rodsLog( LOG_SQL, "cmlCheckResc SQL 2 " );
        }

        bindVars.clear();
        bindVars.push_back( rescName );
        status = cmlGetIntegerValueFromSql(
                     "select resc_id from R_RESC_MAIN where resc_name=?",
                     &iVal, bindVars, icss );
        if ( status ) {
            return CAT_UNKNOWN_RESOURCE;
        }
        return CAT_NO_ACCESS_PERMISSION;
    }

    return iVal;

}