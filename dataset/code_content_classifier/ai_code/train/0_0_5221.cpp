#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> roads(n, {0, 0});
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = {min(a, b), max(a, b)};
    }
    
    int q;
    cin >> q;
    
    vector<int> restored(n + 1, 0);
    long long total_length = 0;
    
    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        
        if (type == '+') {
            int x;
            cin >> x;
            restored[x]++;
        } else if (type == '-') {
            int x;
            cin >> x;
            restored[x]--;
        } else {
            vector<bool> used(n, false);
            for (int j = 1; j <= n; j++) {
                if (restored[j] > 0) {
                    for (int k = 1; k < n; k++) {
                        if (roads[k].first == j || roads[k].second == j) {
                            used[k] = true;
                        }
                    }
                }
            }
            
            long long sum = 0;
            for (int j = 1; j < n; j++) {
                if (used[j]) {
                    sum += roads[j].second;
                }
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}