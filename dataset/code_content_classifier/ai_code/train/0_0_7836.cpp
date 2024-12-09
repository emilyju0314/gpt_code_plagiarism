#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> asphalted;
    
    for (int i = 0; i < n*n; i++) {
        int hi, vi;
        cin >> hi >> vi;
        
        if (asphalted.find(hi) == asphalted.end() && asphalted.find(vi) == asphalted.end()) {
            asphalted.insert(hi);
            asphalted.insert(vi);
            cout << i + 1 << " ";
        }
    }

    return 0;
}