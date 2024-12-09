#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    vector<pair<char, string>> queries;
    
    for(int i = 0; i < n; i++) {
        string query;
        cin >> query;
        
        char di = query[0];
        string ti = query.substr(3);
        
        queries.push_back({di, ti});
    }
    
    for(auto query : queries) {
        char di = query.first;
        string ti = query.second;
        
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == di) {
                s.replace(j, 1, ti);
            }
        }
    }
    
    long long result = 0;
    for(int i = 0; i < s.length(); i++) {
        result = (result * 10 + (s[i] - '0')) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}