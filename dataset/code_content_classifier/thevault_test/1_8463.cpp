int sherlockAndAnagrams(string s) {

    int c = 0;
    map<string, int> hash_map;

    for(int i = 0; i < s.length(); i++){

        for(int j = 1; j <= s.length()-i; j++){

            string tmp = s.substr(i, j);
            sort(tmp.begin(), tmp.end());
            if(!hash_map[tmp]){
                hash_map[tmp] = 1;
            }else{
                hash_map[tmp] += 1;
            }
        }
    }
    
    for(auto i : hash_map){
        cout<<i.first<<"-"<<i.second<<endl;
    }
    

    for(auto i : hash_map){
        c += (i.second * i.second-1)/2;
    }

    return c;
}