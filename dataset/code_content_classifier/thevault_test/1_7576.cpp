void LoadPolicyLine(std::string line, const std::shared_ptr<Model>& model) {
    if(line == "" || line.find("#")==0)
        return;

    std::vector<std::string> tokens = Split(line, ",", -1);
    for (int i = 0; i < tokens.size(); i++)
        tokens[i] = Trim(tokens[i]);

    std::string key = tokens[0];
    std::string sec = key.substr(0,1);
    std::vector<std::string> new_tokens(tokens.begin()+1, tokens.end());

    if (model->m.find(sec) == model->m.end())
        model->m[sec] = AssertionMap();

    (model->m[sec].assertion_map[key]->policy).push_back(new_tokens);
}