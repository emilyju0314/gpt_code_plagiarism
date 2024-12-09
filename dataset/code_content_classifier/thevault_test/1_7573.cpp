ReturnType KeyMatch3(Scope scope) {
    std::string key1 = GetString(scope, 0);
    std::string key2 = GetString(scope, 1);

    PushBooleanValue(scope, KeyMatch3(key1, key2));
    return RETURN_RESULT;
}