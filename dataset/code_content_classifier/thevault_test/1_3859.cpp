int Solution::colorful(int A) {
    string s = to_string(A);
    unordered_map<long long, int> m;
    for(int i = 0; i<s.length(); i++){
        long long temp = 1;
        //Progressively calculating and storing subsequence products
        for(int j = i; j<s.length(); j++){
            temp = temp*(s[j] - '0');
            m[temp]+=1;
            if(m[temp]>1)
                return 0;
        }
    }
    return 1;
}