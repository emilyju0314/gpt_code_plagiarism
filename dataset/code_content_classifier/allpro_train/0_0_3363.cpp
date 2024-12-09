#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    unordered_map<char, int> count;
    for (char c : S) {
        count[c]++;
    }

    for (int i = 0; i < Q; i++) {
        int p;
        char c;
        cin >> p >> c;
        char original_char = S[p-1];
        
        count[original_char]--;
        if (count[original_char] == 0) {
            count.erase(original_char);
        }

        count[c]++;

        int max_count = 0;
        for (auto& pair : count) {
            max_count = max(max_count, pair.second);
        }

        cout << max_count << endl;
        S[p-1] = c;
    }

    return 0;
}