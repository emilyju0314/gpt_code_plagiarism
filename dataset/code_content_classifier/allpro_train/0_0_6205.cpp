#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> bridegrooms(n);
    vector<int> brides(n);

    for (int i = 0; i < n; i++) {
        cin >> bridegrooms[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> brides[i];
    }

    sort(bridegrooms.begin(), bridegrooms.end());
    sort(brides.begin(), brides.end());

    int maxInconvenience = 0;
    for (int i = 0; i < n; i++) {
        int inconvenience = abs(bridegrooms[i] - brides[i]);
        inconvenience = min(inconvenience, L - inconvenience);
        maxInconvenience = max(maxInconvenience, inconvenience);
    }

    cout << maxInconvenience << endl;

    return 0;
}