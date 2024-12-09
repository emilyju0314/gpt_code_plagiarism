#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<pair<int, int>> range(N);
        for (int i = 0; i < N; i++) {
            cin >> range[i].first >> range[i].second;
        }
        
        int total = 1;
        for (int i = 0; i < N; i++) {
            total *= (range[i].second - range[i].first + 1);
        }
        cout << total << endl;
    }
    return 0;
}