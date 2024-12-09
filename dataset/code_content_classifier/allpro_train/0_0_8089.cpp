#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n;
vector<string> dictionary;

map<string, int> cache;

int score(const string& s) {
    if (cache.count(s)) {
        return cache[s];
    }

    int score = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        string new_s = s + c;
        for (const string& word : dictionary) {
            if (word.find(new_s) != string::npos) {
                score += (c - 'a' + 1);
                break;
            }
        }
    }

    cache[s] = score;
    return score;
}

pair<int, int> dfs(const string& s) {
    if (s.length() >= 30) {
        return {0, 0};
    }

    int max_score = 0, min_score = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        string new_s = s + c;
        int cur_score = score(new_s);
        if (cur_score == 0) {
            break;
        }

        auto [next_min, next_max] = dfs(new_s);

        if (next_min < next_max) {
            max_score = max(max_score, next_max + cur_score);
        } else {
            min_score = max(min_score, next_min + cur_score);
        }
    }

    return {min_score, max_score};
}

int main() {
    cin >> n;
    dictionary.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }

    string s = "";
    auto [min_score, max_score] = dfs(s);

    if (min_score > max_score) {
        cout << "Second" << endl;
        cout << min_score << " " << max_score << endl;
    } else {
        cout << "First" << endl;
        cout << max_score << " " << min_score << endl;
    }

    return 0;
}