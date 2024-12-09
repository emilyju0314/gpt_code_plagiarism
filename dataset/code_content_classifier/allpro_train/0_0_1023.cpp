#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    
    vector<pair<int, int>> katanas;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        katanas.push_back({a, b});
    }
    
    sort(katanas.begin(), katanas.end(), greater<pair<int, int>>());
    
    int attacks = 0;
    for (auto katana : katanas) {
        if (katana.first < katana.second && H > 0) {
            H -= katana.second;
            attacks++;
        } else {
            attacks += (H + katana.second - 1) / katana.second;
            break;
        }
    }
    
    cout << attacks << endl;
    
    return 0;
}