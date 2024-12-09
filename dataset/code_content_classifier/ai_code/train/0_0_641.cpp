#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> boys(n);
    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }
    
    cin >> m;
    vector<int> girls(m);
    for (int i = 0; i < m; i++) {
        cin >> girls[i];
    }

    int pairs = 0;
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(boys[i] - girls[j]) <= 1) {
                pairs++;
                girls[j] = -1;
                break;
            }
        }
    }
    
    cout << pairs << endl;
    
    return 0;
}