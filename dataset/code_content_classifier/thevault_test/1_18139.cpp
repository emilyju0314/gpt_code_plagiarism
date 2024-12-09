int
cllExecSqlWithResultBV(
    icatSessionStruct *icss,
    int *stmtNum, const char *sql,
    std::vector<std::string> &bindVars ) {

    for ( int i = 0; i < bindVars.size() && !bindVars[i].empty(); i++ ) {
        cllBindVars[cllBindVarCount++] = bindVars[i].c_str();
    }
    return cllExecSqlWithResult( icss, stmtNum, sql );
}