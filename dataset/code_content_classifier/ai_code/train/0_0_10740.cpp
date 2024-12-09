#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> difficulties(n);
    for(int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    vector<int> max_difficulties;
    vector<int> day_problems;

    for(int i = 0; i < k; i++) {
        int max_difficulty = -1;
        int max_index = -1;
        for(int j = 0; j <= n - k; j++) {
            int current_max = *max_element(difficulties.begin() + j, difficulties.begin() + j + k);
            if(current_max > max_difficulty) {
                max_difficulty = current_max;
                max_index = j;
            }
        }
        max_difficulties.push_back(max_difficulty);
        day_problems.push_back(max_index + 1);
        n -= k - 1;
        difficulties.erase(difficulties.begin() + max_index, difficulties.begin() + (max_index + k));
    }

    int total_profit = 0;
    for(int difficulty : max_difficulties) {
        total_profit += difficulty;
    }

    cout << total_profit << endl;
    for(int num_problems : day_problems) {
        cout << num_problems << " ";
    }

    return 0;
}