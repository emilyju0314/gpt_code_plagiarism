void FileAdapter :: SavePolicy(const std::shared_ptr<Model>& model) {
    if (this->file_path == "") {
        throw CasbinAdapterException("Invalid file path, file path cannot be empty");
    }

    std::string tmp;

    for (std::unordered_map<std::string, std::shared_ptr<Assertion>> :: iterator it = model->m["p"].assertion_map.begin() ; it != model->m["p"].assertion_map.begin() ; it++){
        for (int i = 0 ; i < it->second->policy.size() ; i++){
            tmp += it->first + ", ";
            tmp += ArrayToString(it->second->policy[i]);
            tmp += "\n";
        }
    }

    for (std::unordered_map <std::string, std::shared_ptr<Assertion>> :: iterator it = model->m["g"].assertion_map.begin() ; it != model->m["g"].assertion_map.begin() ; it++){
        for (int i = 0 ; i < it->second->policy.size() ; i++){
            tmp += it->first + ", ";
            tmp += ArrayToString(it->second->policy[i]);
            tmp += "\n";
        }
    }

    return this->SavePolicyFile(RTrim(tmp, "\n"));
}