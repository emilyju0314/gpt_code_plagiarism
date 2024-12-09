rodsLong_t
cmlCheckDirOwn( const char *dirName, const char *userName, const char *userZone,
                icatSessionStruct *icss ) {
    int status;
    rodsLong_t iVal;

    if ( logSQL_CML != 0 ) {
        rodsLog( LOG_SQL, "cmlCheckDirOwn SQL 1 " );
    }

    std::vector<std::string> bindVars;
    bindVars.push_back( dirName );
    bindVars.push_back( userName );
    bindVars.push_back( userZone );
    status = cmlGetIntegerValueFromSql(
                 "select coll_id from R_COLL_MAIN where coll_name=? and coll_owner_name=? and coll_owner_zone=?",
                 &iVal, bindVars, icss );
    if ( status < 0 ) {
        return status;
    }
    return iVal;
}