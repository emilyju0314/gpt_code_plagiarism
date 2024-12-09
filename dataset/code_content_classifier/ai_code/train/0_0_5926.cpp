#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string ciphered, correct;
    cin >> ciphered >> correct;

    vector<int> counts(k * k, 0);

    for(int i = 0; i < n; i++) {
        int ciphered_idx = (ciphered[i] >= 'a') ? ciphered[i] - 'a' : ciphered[i] - 'A' + 26;
        int correct_idx = (correct[i] >= 'a') ? correct[i] - 'a' : correct[i] - 'A' + 26;
        counts[ciphered_idx * k + correct_idx]++;
    }

    vector<pair<int, int>> freq;
    for(int i = 0; i < k * k; i++) {
        freq.push_back({counts[i], i});
    }

    sort(freq.rbegin(), freq.rend());

    vector<char> mapping(k);
    vector<bool> used(k);

    for(auto p : freq) {
        int ciphered_idx = p.second / k;
        int correct_idx = p.second % k;

        if(!used[ciphered_idx] && mapping[correct_idx] == 0) {
            mapping[correct_idx] = (ciphered_idx < 26) ? ciphered_idx + 'a' : ciphered_idx - 26 + 'A';
            used[ciphered_idx] = true;
        }
    }

    int score = 0;
    for(int i = 0; i < n; i++) {
        int ciphered_idx = (ciphered[i] >= 'a') ? ciphered[i] - 'a' : ciphered[i] - 'A' + 26;
        int correct_idx = (correct[i] >= 'a') ? correct[i] - 'a' : correct[i] - 'A' + 26;

        if(mapping[correct_idx] == ((ciphered_idx < 26) ? ciphered_idx + 'a' : ciphered_idx - 26 + 'A')) {
            score++;
        }
        
    }

    cout << score << endl;
    for(char c : mapping) {
        cout << c;
    }
    cout << endl;

    return 0;
}