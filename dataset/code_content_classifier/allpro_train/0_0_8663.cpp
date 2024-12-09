#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string trophies;
    cin >> n >> trophies;

    int maxBeauty = 0;
    int currentBeauty = 0;

    for (int i = 0; i < n; i++) {
        if (trophies[i] == 'G') {
            currentBeauty++;
        } else {
            maxBeauty = max(maxBeauty, currentBeauty);
            currentBeauty = 0;
        }
    }

    maxBeauty = max(maxBeauty, currentBeauty);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = currentBeauty;
        if (trophies[i] == 'S') {
            temp++;
            if (i > 0 && i < n - 1 && trophies[i-1] == 'G' && trophies[i+1] == 'G') {
                temp++;
            }
        }
        ans = max(ans, temp);
    }

    cout << min(ans, maxBeauty) << endl;

    return 0;
}