#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countChanges(const string& a, const string& b, int k) {
    int changes = 0;
    for (int i = 0; i < b.size(); i++) {
        if (a[i] != b[i]) {
            changes++;
        }
    }
    
    vector<int> prefixChanges(a.size());
    prefixChanges[0] = changes;
    
    for (int i = b.size(); i < a.size(); i++) {
        if (a[i] != b[i - b.size()]) {
            changes++;
        }
        if (a[i - b.size()] != b[0]) {
            changes--;
        }
        prefixChanges[i - b.size() + 1] = changes;
    }
    
    int minChanges = changes;
    for (int i = 0; i <= a.size() - b.size(); i++) {
        if (prefixChanges[i] == k) {
            return 0;
        }
        minChanges = min(minChanges, abs(k - prefixChanges[i]));
    }
    
    return minChanges;
}

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    for (int k = 0; k <= n - m + 1; k++) {
        cout << countChanges(a, b, k) << " ";
    }
    
    return 0;
}