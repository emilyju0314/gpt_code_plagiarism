ReturnType IPMatch(Scope scope) {
    std::string ip1 = GetString(scope, 0);
    std::string ip2 = GetString(scope, 1);

    PushBooleanValue(scope, IPMatch(ip1, ip2));
    return RETURN_RESULT;
}