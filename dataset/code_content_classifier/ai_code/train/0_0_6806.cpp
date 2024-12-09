#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int totalTime = 0;
    vector<pair<int, int>> order;
    
    for(int i = 0; i < (n + 1) / 2; i++) {
        if(i == 0) {
            if(n % 2 == 0) {
                totalTime += a[0];
                order.push_back({1, 2});
            } else {
                totalTime += a[1];
                order.push_back({1, 3});
                order.push_back({2});
            }
        } else {
            int maxTime = max(a[i], a[n - 1 - i]);
            totalTime += maxTime;
            order.push_back({a[i], a[n - 1 - i]});
        }
    }
    
    cout << totalTime << endl;
    for(auto o : order) {
        for(int val : o) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}