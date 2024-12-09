#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> parent(1000001);

vector<int> findPath(int v, const vector<int>& nums) {
    vector<int> path;
    while (v != 0) {
        path.push_back(nums[v]);
        v = parent[v];
    }
    return path;
}

void answerQuestions(int n, const vector<int>& nums, const vector<int>& questions) {
    unordered_map<int, int> freq;
    for (int i = 1; i <= n; i++) {
        vector<int> path = findPath(i, nums);
        for (int num : path) {
            freq[num]++;
        }
    }
    for (int i = 0; i < questions.size(); i += 3) {
        int v = questions[i];
        int l = questions[i + 1];
        int k = questions[i + 2];
        vector<int> path = findPath(v, nums);
        for (int num : path) {
            if (freq[num] < l) {
                freq.erase(num);
            }
        }
        if (freq.size() < k) {
            cout << -1 << " ";
        } else {
            cout << freq.begin()->first << " "; // Arbitrary choice from remaining sequence
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
        }

        vector<int> questions(q * 3);
        for (int i = 0; i < q * 3; i++) {
            cin >> questions[i];
        }

        answerQuestions(n, nums, questions);
    }

    return 0;
}