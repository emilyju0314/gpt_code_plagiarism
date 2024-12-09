std::string number_palindrome(int N) {
    if(N < 10){
        return std::string(1, char('0' + N));
    }
    long long sum = 0, digits = 1, v;
    for(; ; digits++){
        if(digits % 2 == 0){
            v = std::pow(10, digits/2-1) * 9;
        }else{
            v = std::pow(10, (digits+1)/2-1) * 9;
        }
        if(v + sum >= N) break;
        sum += v;
    }
    //I have to find the M-th palindromic number with X digits:
    long long Mth = N-sum;
    long long sz = (digits+1) / 2;
    long long pattern = std::pow(10, sz-1);
    pattern += (Mth-1);
    std::vector<int> tmp;
    while(pattern > 0){
        tmp.insert(tmp.begin(), pattern % 10);
        pattern /= 10;
    }
    int idx = digits-tmp.size() - 1;
    std::string ans = "";
    for(int i = 0; i < tmp.size(); i++){
        ans += std::string(1, char('0' + tmp[i]));
    }
    for(;idx >= 0;){
        ans += std::string(1, char('0' + tmp[idx--]));
    }
    return ans;
}