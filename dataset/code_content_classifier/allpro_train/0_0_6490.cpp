#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;

    while (cin >> N >> M && N != 0) {
        vector<int> max_recommendation(M+1, 0);

        for (int i = 0; i < N; i++) {
            int d, v;
            cin >> d >> v;
            max_recommendation[d] = max(max_recommendation[d], v);
        }

        int sum = 0;
        for (int i = 1; i <= M; i++) {
            sum += max_recommendation[i];
        }

        cout << sum << endl;
    }

    return 0;
}