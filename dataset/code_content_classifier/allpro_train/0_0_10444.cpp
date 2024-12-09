#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

struct Barrier {
    int row, left, right, height;
};

bool compareLeft(const Barrier& b1, const Barrier& b2) {
    return b1.left < b2.left;
}

bool compareRight(const Barrier& b1, const Barrier& b2) {
    return b1.right < b2.right;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<Barrier> barriers(n);
    for(int i = 0; i < n; i++) {
        cin >> barriers[i].row >> barriers[i].left >> barriers[i].right >> barriers[i].height;
    }

    sort(barriers.begin(), barriers.end(), compareLeft);
    vector<long long> prefixSums(w+1, 0);
    int currBarrier = 0;
    for(int col = 1; col < w+1; col++) {
        while(currBarrier < n && barriers[currBarrier].left == col) {
            prefixSums[col] += barriers[currBarrier].height;
            currBarrier++;
        }
        prefixSums[col] += prefixSums[col-1];
    }

    sort(barriers.begin(), barriers.end(), compareRight);
    vector<long long> suffixSums(w+1, 0);
    currBarrier = n - 1;
    for(int col = w; col > 0; col--) {
        while(currBarrier >= 0 && barriers[currBarrier].right == col) {
            suffixSums[col] += barriers[currBarrier].height;
            currBarrier--;
        }
        suffixSums[col] += suffixSums[col+1];
    }

    long long result = 0;
    for(int col = 1; col < w+1; col++) {
        result += (h + 1 - prefixSums[col] - suffixSums[col]);
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}