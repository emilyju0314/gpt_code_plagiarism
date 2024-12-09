int MainTable::max_as_element(std::vector<std::vector<int> > &v){
    int current = 0;
    for(unsigned int i=0;i<v.size();i++){
        for(unsigned int j=0;j<v[i].size();j++){
            if(v[i][j] > current)
                current = v[i][j];
        }
    }
    return current;
}