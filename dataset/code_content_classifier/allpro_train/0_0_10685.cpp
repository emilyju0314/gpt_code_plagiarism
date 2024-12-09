#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> bags;
vector<int> nums;

bool solve(int idx, int sum) {
    if(idx == bags.size()) {
        return sum == 0;
    }

    for(int i = 0; i <= nums[idx]; i++) {
        bags[idx][0] = i;
        if(solve(idx + 1, sum - i)) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, s;
    cin >> n >> s;

    bags.resize(n);
    nums.resize(n);

    for(int i = 0; i < n; i++) {
        int coins;
        cin >> coins;
        bags[i].resize(coins + 1);
        bags[i][coins] = 0;
        nums[i] = coins;
    }

    if(solve(0, s)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < bags[i].size(); j++) {
                cout << bags[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}