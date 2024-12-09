int
generateSpecialQuery( genQueryInp_t genQueryInp, char *resultingSQL ) {
    static char rescName[LONG_NAME_LEN];
    static char userName[NAME_LEN] = "";
    static char userZone[NAME_LEN] = "";

    char quotaQuery1[] = "( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_RESC_MAIN RM, R_USER_GROUP UG, R_USER_MAIN UM2 where QM.resc_id = RM.resc_id AND (QM.user_id = UG.group_user_id and UM2.user_name = ? and UM2.zone_name = ? and UG.user_id = UM2.user_id )) UNION ( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_USER_GROUP UG, R_USER_MAIN UM2, R_RESC_MAIN RM where QM.resc_id = '0' AND (QM.user_id = UG.group_user_id and UM2.user_name = ? and UM2.zone_name = ? and UG.user_id = UM2.user_id)) UNION ( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_USER_MAIN UM, R_RESC_MAIN RM WHERE (QM.resc_id = RM.resc_id or QM.resc_id = '0') AND (QM.user_id = UM.user_id and UM.user_name = ? and UM.zone_name = ? )) order by quota_over DESC";

    char quotaQuery2[] = "( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_RESC_MAIN RM, R_USER_GROUP UG, R_USER_MAIN UM2 where QM.resc_id = RM.resc_id AND RM.resc_name = ? AND (QM.user_id = UG.group_user_id and UM2.user_name = ? and UM2.zone_name = ? and UG.user_id = UM2.user_id )) UNION ( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_USER_GROUP UG, R_USER_MAIN UM2, R_RESC_MAIN RM where QM.resc_id = '0' AND RM.resc_name = ? AND (QM.user_id = UG.group_user_id and UM2.user_name = ? and UM2.zone_name = ? and UG.user_id = UM2.user_id)) UNION ( select distinct QM.user_id, RM.resc_name, QM.quota_limit, QM.quota_over, QM.resc_id from R_QUOTA_MAIN QM, R_USER_MAIN UM, R_RESC_MAIN RM WHERE (QM.resc_id = RM.resc_id or QM.resc_id = '0') AND RM.resc_name = ? AND (QM.user_id = UM.user_id and UM.user_name = ? and UM.zone_name = ? )) order by quota_over DESC";

    int i, valid = 0;
    int cllCounter = cllBindVarCount;

    for ( i = 0; i < genQueryInp.sqlCondInp.len; i++ ) {
        if ( genQueryInp.sqlCondInp.inx[i] == COL_USER_NAME ) {
            int status = parseUserName( genQueryInp.sqlCondInp.value[i], userName,
                                        userZone );
            if ( status ) {
                rodsLog( LOG_ERROR, "parseUserName failed in generateSpecialQuery on %s with status %d.",
                         genQueryInp.sqlCondInp.value[i], status );
                return status;
            }
            if ( userZone[0] == '\0' ) {
                std::string zoneName;
                if ( !chlGetLocalZone( zoneName ) ) {

                }

                snprintf( userZone, sizeof( userZone ), "%s", zoneName.c_str() );
                rodsLog( LOG_ERROR, "userZone1=:%s:\n", userZone );
            }
            rodsLog( LOG_DEBUG, "spQuery(1) userZone2=:%s:\n", userZone );
            rodsLog( LOG_DEBUG, "spQuery(1) userName=:%s:\n", userName );
            rodsLog( LOG_DEBUG, "spQuery(1) in=:%s:\n",
                     genQueryInp.sqlCondInp.value[i] );
            cllBindVars[cllBindVarCount++] = userName;
            cllBindVars[cllBindVarCount++] = userZone;
            cllBindVars[cllBindVarCount++] = userName;
            cllBindVars[cllBindVarCount++] = userZone;
            cllBindVars[cllBindVarCount++] = userName;
            cllBindVars[cllBindVarCount++] = userZone;
            strncpy( resultingSQL, quotaQuery1, MAX_SQL_SIZE_GQ );
            valid = 1;
        }
    }
    if ( valid == 0 ) {
        return CAT_INVALID_ARGUMENT;
    }
    for ( i = 0; i < genQueryInp.sqlCondInp.len; i++ ) {
        if ( genQueryInp.sqlCondInp.inx[i] == COL_R_RESC_NAME ) {
            rodsLog( LOG_DEBUG, "spQuery(2) userZone2=:%s:\n", userZone );
            rodsLog( LOG_DEBUG, "spQuery(2) userName=:%s:\n", userName );
            rodsLog( LOG_DEBUG, "spQuery(2) in=:%s:\n",
                     genQueryInp.sqlCondInp.value[i] );
            snprintf( rescName, sizeof( rescName ), "%s", genQueryInp.sqlCondInp.value[i] );
            cllBindVars[cllCounter++] = rescName;
            cllBindVars[cllCounter++] = userName;
            cllBindVars[cllCounter++] = userZone;
            cllBindVars[cllCounter++] = rescName;
            cllBindVars[cllCounter++] = userName;
            cllBindVars[cllCounter++] = userZone;
            cllBindVars[cllCounter++] = rescName;
            cllBindVars[cllCounter++] = userName;
            cllBindVars[cllCounter++] = userZone;

            strncpy( resultingSQL, quotaQuery2, MAX_SQL_SIZE_GQ );
            cllBindVarCount = cllCounter;
        }
    }
    return 0;
}