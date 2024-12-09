#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> beauty(n);
    for(int i = 0; i < n; i++) {
        cin >> beauty[i];
    }

    string colors;
    cin >> colors;

    int maxBeauty = -1;
    for(char c = 'R'; c <= 'O'; c++) {
        int count = 0;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(colors[i] == c) {
                count++;
                v.push_back(beauty[i]);
            }
        }

        if(count < k) {
            continue;
        }

        sort(v.begin(), v.end(), greater<int>());
        int sum = 0;
        for(int i = 0; i < k-1; i++) {
            sum += v[i];
        }

        maxBeauty = max(maxBeauty, sum);
    }

    cout << maxBeauty << endl;

    return 0;
}