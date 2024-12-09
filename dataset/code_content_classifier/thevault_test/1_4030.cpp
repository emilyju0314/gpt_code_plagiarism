inline size_t appendAndOrGetIndex(vector<Governor> & vec, Governor const & gov) {
    size_t preAddSize = vec.size();

    for (int i=0; i<preAddSize; i++)
        if (vec[i].name == gov.name) 
            return i;

    vec.push_back(gov);
    return preAddSize;
}