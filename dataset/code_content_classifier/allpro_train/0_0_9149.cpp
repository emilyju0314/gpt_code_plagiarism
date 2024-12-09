#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Walrus {
    int height;
    int growth;

    Walrus(int h, int g) : height(h), growth(g) {}
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Walrus> walruses;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        walruses.push_back(Walrus(a, b));
    }

    for (int i = 0; i < q; i++) {
        int l, r, t;
        cin >> l >> r >> t;

        int max_height = -1;
        int walrus_num = -1;

        for (int j = l-1; j < r; j++) {
            int current_height = walruses[j].height + walruses[j].growth * t;
            if (current_height > max_height) {
                max_height = current_height;
                walrus_num = j+1;
            }
        }

        cout << walrus_num << endl;
    }

    return 0;
}