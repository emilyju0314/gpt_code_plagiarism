void Model::ClearPolicy() {
    // Caching "p" assertion map by reference for the scope of this function
    for (auto [_, assertion_ptr] : this->m["p"].assertion_map) {
        if(assertion_ptr->policy.size() > 0)
            assertion_ptr->policy.clear();
    }

    // Caching "g" assertion map by reference for the scope of this function
    for (auto [_, assertion_ptr] : this->m["g"].assertion_map){
        if(assertion_ptr->policy.size() > 0)
            assertion_ptr->policy.clear();
    }
}