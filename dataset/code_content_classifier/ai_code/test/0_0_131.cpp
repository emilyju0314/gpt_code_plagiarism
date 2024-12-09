#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_exchanges_needed = 0;
    pair<int, int> optimal_pair;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int exchanges_needed = 0;
            int x = a[i], y = a[j];
            while(x != y) {
                exchanges_needed++;
                if(x > y) {
                    x = x - pow(2, (int)log2(x - y));
                } else {
                    y = y - pow(2, (int)log2(y - x));
                }
            }
            if(exchanges_needed > max_exchanges_needed) {
                max_exchanges_needed = exchanges_needed;
                optimal_pair = {i+1, j+1};
            }
        }
    }

    cout << optimal_pair.first << " " << optimal_pair.second << " " << max_exchanges_needed << endl;

    return 0;
}