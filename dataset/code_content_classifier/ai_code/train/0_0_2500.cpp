#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;
    string S;
    cin >> K >> S;

    vector<int> nums;
    int start = 0;

    for (int i = 0; i < K; i++) {
        int len = i + 1;
        if (start + len > S.size()) {
            break;
        }
        nums.push_back(stoi(S.substr(start, len)));
        start += len;
    }

    if (start < S.size()) {
        nums.push_back(stoi(S.substr(start)));
    }

    sort(nums.begin(), nums.end());

    cout << nums.front() << endl;

    return 0;
}