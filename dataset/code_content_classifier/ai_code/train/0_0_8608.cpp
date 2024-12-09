#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector<int>& a) {
    int inversions = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] > a[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

void reverseSubarrays(vector<int>& a, int qi) {
    int n = a.size() / 2;
    int partSize = 1 << qi; // 2^qi
    for (int i = 0; i < n; i += partSize) {
        reverse(a.begin() + i, a.begin() + i + partSize);
    }
}

int main() {
    int n, m;
    cin >> n;

    vector<int> a(2 << n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int qi;
        cin >> qi;

        reverseSubarrays(a, qi);
        cout << countInversions(a) << endl;
    }

    return 0;
}