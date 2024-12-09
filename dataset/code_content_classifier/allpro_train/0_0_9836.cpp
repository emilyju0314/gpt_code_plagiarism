#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b, q;
    cin >> n >> b >> q;

    vector<pair<int, int>> hints(q);
    for (int i = 0; i < q; i++) {
        int upToi, quantityi;
        cin >> upToi >> quantityi;
        hints[i] = make_pair(upToi, quantityi);
    }

    vector<int> elements;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            int cnt = 0;
            for (auto hint : hints) {
                if (hint.first >= i && hint.first % 5 == j) {
                    cnt += hint.second;
                }
            }
            for (int k = 0; k < cnt; k++) {
                elements.push_back(i);
            }
        }
    }

    sort(elements.begin(), elements.end());
    elements.resize(n);

    if (elements.back() <= b) {
        cout << "fair" << endl;
    } else {
        cout << "unfair" << endl;
    }

    return 0;
}