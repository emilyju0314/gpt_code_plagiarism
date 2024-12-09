#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

class ParseError{};
struct Result{
    int p, val;
    Result(int a, int b) : p(a), val(b) {}
};
struct Parser{
    map<char, int> order_dict;
    Parser(){
        order_dict['*'] = 5;
        order_dict['+'] = 4;
        order_dict['-'] = 4;
        order_dict['&'] = 3;
        order_dict['^'] = 2;
        order_dict['|'] = 1;
    }
    int eval(string s){
        Result r = expr(s, 0, 0);
        if(r.p != s.size()) throw ParseError();
        return r.val;
    }
    int calc(int a, int b, char c){
        //printf("%d%c%d\n", a, c, b);
        if(c == '*') return a * b;
        if(c == '+') return a + b;
        if(c == '-') return a - b;
        if(c == '&') return a & b;
        if(c == '^') return a ^ b;
        if(c == '|') return a | b;
        assert(false);
    }
    Result expr(string s, int k, int order){
        if(order == 5) return term(s, k);
        Result r = expr(s, k, order + 1);
        while(order_dict[ s[r.p] ] == order + 1){
            Result t = expr(s, r.p + 1, order + 1);
            r.val = calc(r.val, t.val, s[r.p]);
            r.p = t.p;
        }
        return r;
    }
    Result term(string s, int k){
        if(s[k] == '('){
            Result r = expr(s, k + 1, 0);
            if(s[r.p++] != ')') throw ParseError();
            return r;
        }else if(isdigit(s[k])){
            if(s[k] == '0') throw ParseError();
            int val = 0;
            while(isdigit(s[k])){
                val = val * 10 + s[k++] - '0';
            }
            return Result(k, val);
        }else {
            throw ParseError();
        }
    }
    bool valid(string s){
        try{
            eval(s);
            return true;
        }catch(...){
            return false;
        }
    }
};
Parser P;

int dfs(const string& s, int n, int type){
    string cs = "()*+-&^|0123456789";
    vector<string> next;
    if(n == 0){
        try{
            return P.eval(s);
        }catch(...){
            return (type == 0 ? INT_MAX : INT_MIN);
        }
    }
    // add 
    for(int i = 0; i <= s.size(); i++){
        for(char c : cs) if(s[i] != c){
            string ns = s.substr(0, i) + string(1, c) + s.substr(i);
            next.push_back(ns);
        }
    }
    // delete
    for(int i = 0; i < s.size(); i++){
        string ns = s.substr(0, i) + s.substr(i + 1);
        next.push_back(ns);
    }
    int res = (type == 0 ? INT_MIN : INT_MAX);
    for(string ns : next) if(true && P.valid(ns)) {
        //cout << s << "->" << ns << endl;
        if(type == 0){
            res = max(res, dfs(ns, n - 1, type ^ 1));
        }else{
            res = min(res, dfs(ns, n - 1, type ^ 1));
        }
    }
    return res;
}

int main(){
    int N;
    while(cin >> N && N > 0){
        if(N % 2 == 0) N = 2;
        else N = 1;
        string s;
        cin >> s;
        cout << dfs(s, N, 0) << endl;
    }
    return 0;
}