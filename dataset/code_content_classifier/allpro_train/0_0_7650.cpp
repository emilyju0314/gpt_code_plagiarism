#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> beauties(n);
    for (int i = 0; i < n; i++) {
        cin >> beauties[i];
    }

    sort(beauties.begin(), beauties.end());

    int idx = 0;
    for (int i = 0; i < k; i++) {
        cout << "1 " << beauties[idx++] << endl;
    }
    
    return 0;
}