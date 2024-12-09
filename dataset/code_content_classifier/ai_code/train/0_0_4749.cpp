#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Doll {
    int height;
    int radius;
};

int main() {
    int n, m;
    while (cin >> n && n != 0) {
        vector<Doll> ichiroDolls(n);
        for (int i = 0; i < n; i++) {
            cin >> ichiroDolls[i].height >> ichiroDolls[i].radius;
        }

        cin >> m;
        vector<Doll> jiroDolls(m);
        for (int i = 0; i < m; i++) {
            cin >> jiroDolls[i].height >> jiroDolls[i].radius;
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ichiroDolls[i].height > jiroDolls[j].height && ichiroDolls[i].radius > jiroDolls[j].radius) {
                    k++;
                } else if (ichiroDolls[i].height < jiroDolls[j].height && ichiroDolls[i].radius < jiroDolls[j].radius) {
                    k++;
                }
            }
        }

        cout << k << endl;
    }

    return 0;
}