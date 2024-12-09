#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countChanges(string a, string b) {
    int changes = 0;
    for (int i = 0; i < b.length(); i++) {
        if (a[i] != b[i]) {
            changes++;
        }
    }
    return changes;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    vector<int> result(n - m + 2, -1);
    
    for (int k = 0; k <= n - m + 1; k++) {
        int totalChanges = 0;
        for (int i = 0; i <= n - m; i++) {
            string sub = a.substr(i, m);
            int changes = countChanges(sub, b);
            if (changes == k) {
                totalChanges++;
            }
        }
        result[k] = totalChanges;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}