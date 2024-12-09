int cmlGetGroupMemberCount( const char *groupName, icatSessionStruct *icss ) {

    rodsLong_t iVal;
    int status;
    std::vector<std::string> bindVars;
    bindVars.push_back( groupName );
    status = cmlGetIntegerValueFromSql(
                 "select count(user_id) from r_user_group where  group_user_id != user_id and group_user_id in (select user_id from r_user_main where user_name=? and user_type_name='rodsgroup')",
                 &iVal, bindVars, icss );
    if ( status == 0 ) {
        status = iVal;
    }
    return status;
}