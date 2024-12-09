#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> testimonies[N];
    int honestCount = 0;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        
        vector<pair<int, int>> testimonyList;
        for (int j = 0; j < A; j++) {
            int x, y;
            cin >> x >> y;
            testimonyList.push_back(make_pair(x, y));
        }

        testimonies[i] = testimonyList;
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        bool isPossible = true;
        for (int i = 0; i < N; i++) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }

            for (pair<int, int> testimony : testimonies[i]) {
                int x = testimony.first - 1;
                int y = testimony.second;

                if ((mask & (1 << x)) != y << x) {
                    isPossible = false;
                    break;
                }
            }

            if (!isPossible) {
                break;
            }
        }

        if (isPossible) {
            int count = __builtin_popcount(mask);
            honestCount = max(honestCount, count);
        }
    }

    cout << honestCount << endl;

    return 0;
}