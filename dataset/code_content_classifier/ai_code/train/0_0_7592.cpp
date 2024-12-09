#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> variables(n);
    for (int i = 0; i < n; i++) {
        cin >> variables[i];
    }
    
    sort(variables.begin(), variables.end());
    
    int totalLength = 0;
    for (int i = 1; i < n; i++) {
        int prefixLength = 0;
        
        for (int j = 0; j < variables[i].size(); j++) {
            if (variables[i-1][j] == variables[i][j]) {
                prefixLength++;
            } else {
                break;
            }
        }
        
        totalLength += variables[i].size() - prefixLength;
    }
    
    totalLength += variables[0].size();
    
    cout << totalLength << endl;
    
    return 0;
}