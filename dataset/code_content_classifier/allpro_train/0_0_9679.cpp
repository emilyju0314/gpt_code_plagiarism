#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_set<int> snukes_with_snacks;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int snuke;
            cin >> snuke;
            snukes_with_snacks.insert(snuke);
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (snukes_with_snacks.find(i) == snukes_with_snacks.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}