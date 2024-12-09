ReturnType RegexMatch(Scope scope) {
    std::string key1 = GetString(scope, 0);
    std::string key2 = GetString(scope, 1);

    PushBooleanValue(scope, RegexMatch(key1, key2));
    return RETURN_RESULT;
}