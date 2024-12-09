#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> cnf(n);
    vector<int> variables(m+1, -1);
    
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        cnf[i].resize(k);
        for(int j=0; j<k; j++) {
            cin >> cnf[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        bool satisfied = false;
        for(int j=0; j<cnf[i].size(); j++) {
            int var = abs(cnf[i][j]);
            if(variables[var] != -1) {
                if(cnf[i][j] < 0) {
                    if(variables[var] == 0) {
                        satisfied = true;
                        break;
                    }
                } else {
                    if(variables[var] == 1) {
                        satisfied = true;
                        break;
                    }
                }
            }
        }
        if(!satisfied) {
            for(int j=0; j<cnf[i].size(); j++) {
                int var = abs(cnf[i][j]);
                if(variables[var] == -1) {
                    if(cnf[i][j] < 0) {
                        variables[var] = 0;
                    } else {
                        variables[var] = 1;
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=m; i++) {
        if(variables[i] == -1) {
            variables[i] = 0;
        }
    }
    
    bool satisfiable = true;
    for(int i=0; i<n; i++) {
        bool clause_satisfied = false;
        for(int j=0; j<cnf[i].size(); j++) {
            int var = abs(cnf[i][j]);
            if((cnf[i][j] < 0 && variables[var] == 0) || (cnf[i][j] > 0 && variables[var] == 1)) {
                clause_satisfied = true;
                break;
            }
        }
        if(!clause_satisfied) {
            satisfiable = false;
            break;
        }
    }
    
    if(satisfiable) {
        cout << "YES" << endl;
        for(int i=1; i<=m; i++) {
            cout << variables[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}