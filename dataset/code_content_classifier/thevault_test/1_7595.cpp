bool Model::AddDef(const std::string& sec, const std::string& key, const std::string& value) {
    if(value == "")
        return false;

    std::shared_ptr<Assertion> ast = std::make_shared<Assertion>();
    ast->key = key;
    ast->value = value;
    if (sec == "r" || sec == "p") {
        ast->tokens = Split(ast->value, ",");
        for (std::string& token : ast->tokens)
            token = key + "_" + Trim(token);
    }
    else
        ast->value = RemoveComments(ast->value);

    if (m.find(sec) == m.end())
        m[sec] = AssertionMap();
    ast->policy = {};

    m[sec].assertion_map[key] = ast;

    return true;
}