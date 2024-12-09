#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> type(n);
    vector<int> problems(n);
    
    for (int i = 0; i < n; i++) {
        cin >> type[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }
    
    int q;
    cin >> q;
    
    vector<pair<int, int>> assumptions(q);
    
    for (int i = 0; i < q; i++) {
        cin >> assumptions[i].first >> assumptions[i].second;
    }
    
    vector<int> prefixMath(n+1, 0);
    vector<int> prefixEcon(n+1, 0);
    
    for (int i = 0; i < n; i++) {
        prefixMath[i+1] = prefixMath[i];
        prefixEcon[i+1] = prefixEcon[i];
        
        if (type[i] == 1) {
            prefixMath[i+1] += problems[i];
        } else {
            prefixEcon[i+1] += problems[i];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int l = assumptions[i].first;
        int r = assumptions[i].second;
        
        int count = 0;
        
        for (int start = l; start <= r; start++) {
            for (int end = start; end <= r; end++) {
                int mathProblems = prefixMath[end+1] - prefixMath[start];
                int econProblems = prefixEcon[end+1] - prefixEcon[start];
                
                if (mathProblems - econProblems == k) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}