#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone {
    int id;
    long long volume;

    bool operator<(const Stone& other) const {
        return volume < other.volume;
    }
};

long long calculateVolume(long long a, long long b, long long c) {
    return a * b * c;
}

int main() {
    int n;
    cin >> n;

    vector<Stone> stones;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        long long volume = calculateVolume(a, b, c);
        stones.push_back({i, volume});
    }

    sort(stones.rbegin(), stones.rend());

    long long maxVolume = 0;
    vector<int> selectedStones;

    for (int i = 0; i < min(n, 2); i++) {
        vector<int> candidateStones;
        candidateStones.push_back(stones[i].id);

        if (i == 1) {
            candidateStones.push_back(stones[i+1].id);
        }

        long long currentVolume = 1LL;
        for (int stoneId : candidateStones) {
            currentVolume *= stones[i].volume;
        }

        if (currentVolume > maxVolume) {
            maxVolume = currentVolume;
            selectedStones = candidateStones;
        }
    }

    cout << selectedStones.size() << endl;
    for (int stoneId : selectedStones) {
        cout << stoneId << " ";
    }

    return 0;
}