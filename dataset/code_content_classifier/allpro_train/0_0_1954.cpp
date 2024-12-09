#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> clauses(n);
    unordered_map<int, int> variables;
    
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        clauses[i].resize(k);
        
        for(int j=0; j<k; j++) {
            cin >> clauses[i][j];
            variables[abs(clauses[i][j])]++;
        }
    }
    
    long long result = 1;
    for(auto& var_count : variables) {
        result = (result * 2) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}