#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> residents(n+1);
        unordered_set<int> cats;
        
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            residents[a].push_back(b);
            cats.insert(b);
        }
        
        bool possible = false;
        for (int i = 1; i <= n; i++) {
            if (residents[i].size() < n-1 && cats.size() < n) {
                possible = true;
                cout << "Yes" << endl;
                cout << residents[i].size() << " " << n-residents[i].size() << endl;
                for (int j = 1; j <= n; j++) {
                    if (residents[i].size() > 0 && residents[i].size() < n-1 && residents[i].front() != j) {
                        cout << i << " ";
                        residents[i].pop_back();
                    }
                }
                for (int j = 1; j <= n; j++) {
                    if (cats.find(j) == cats.end()) {
                        cout << j << " ";
                    }
                }
                break;
            }
        }
        
        if (!possible) {
            cout << "No" << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}