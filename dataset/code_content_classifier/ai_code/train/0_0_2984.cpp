#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_displeasure(vector<int>& playlist, int m, int li, int ri, int xi) {
    int min_quality = INT_MAX;
    for(int i = li - 1; i <= ri - m; i++) {
        int displeasure = 0;
        for(int j = 0; j < m; j++) {
            if(playlist[i+j] < xi) {
                displeasure++;
            }
        }
        min_quality = min(min_quality, displeasure);
    }
    return min_quality;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> playlist(n);
    for(int i = 0; i < n; i++) {
        cin >> playlist[i];
    }

    int s;
    cin >> s;

    for(int i = 0; i < s; i++) {
        int li, ri, xi;
        cin >> li >> ri >> xi;
        int ans = calculate_displeasure(playlist, m, li, ri, xi);
        cout << ans << endl;
    }

    return 0;
}