int
icatApplyRule( rsComm_t *rsComm, char *ruleName, char *arg1 ) {
    ruleExecInfo_t rei;
    int status;
    const char *args[2];

    rodsLog( LOG_NOTICE, "icatApplyRule called" );
    memset( ( char* )&rei, 0, sizeof( rei ) );
    args[0] = arg1;
    rei.rsComm = rsComm;
    rei.uoic = &rsComm->clientUser;
    rei.uoip = &rsComm->proxyUser;
    status =  applyRuleArg( ruleName,
                            args, 1, &rei, NO_SAVE_REI );
    return status;
}