#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcSimilarity(vector<int>& a, vector<int>& b, int k) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (i + k > a.size()) {
                return -1;
            }
            for (int j = 0; j < k; j++) {
                a[i+j] ^= a[i+j] ^ b[i+j];
            }
        }
    }
    return diff;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int initialSimilarity = calcSimilarity(a, b, k);
    cout << initialSimilarity << endl;

    for (int i = 0; i < q; i++) {
        char s;
        int p, v;
        cin >> s >> p >> v;
        
        if (s == 'a') {
            a[p-1] = v;
        } else {
            b[p-1] = v;
        }

        int similarity = calcSimilarity(a, b, k);
        cout << similarity << endl;
    }

    return 0;
}