#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> rotate(const vector<int>& seq) {
    vector<int> res(seq);
    rotate(res.begin(), res.begin() + 1, res.end());
    return res;
}

vector<int> rewrite(const vector<int>& seq, const vector<int>& rule) {
    vector<int> res(seq);
    auto it = search(res.begin(), res.end(), rule.begin(), rule.end());
    if (it != res.end()) {
        it = res.erase(it, it + rule.size());
        res.insert(it, rule.back());
    }
    return res;
}

bool equalAfterTransform(const vector<int>& seq1, const vector<int>& seq2, const vector<vector<int>>& rules) {
    unordered_map<vector<int>, int> states;
    for (int i = 0; i < 2; ++i) {
        if (!states.count(i == 0 ? seq1 : seq2)) {
            states[i == 0 ? seq1 : seq2] = i;
        }
    }
    
    int n = static_cast<int>(seq1.size());
    
    bool modified = true;
    while (modified) {
        modified = false;
        vector<int> tmp1 = rotate(seq1);
        vector<int> tmp2 = rotate(seq2);
        if (!states.count(tmp1)) {
            states[tmp1] = n;
        } else if (states[tmp1] == n) {
            return true;
        }
        if (!states.count(tmp2)) {
            states[tmp2] = n;
        } else if (states[tmp2] == n) {
            return true;
        }
        
        for (const auto& rule : rules) {
            vector<int> new_seq1 = rewrite(seq1, rule);
            vector<int> new_seq2 = rewrite(seq2, rule);
            if (!states.count(new_seq1)) {
                states[new_seq1] = n;
            } else if (states[new_seq1] == n) {
                return true;
            }
            if (!states.count(new_seq2)) {
                states[new_seq2] = n;
            } else if (states[new_seq2] == n) {
                return true;
            }
            if (new_seq1 != seq1 || new_seq2 != seq2) {
                modified = true;
            }
        }
        
        seq1 = move(tmp1);
        seq2 = move(tmp2);
    }
    
    return false;
}

int main() {
    int n, m, r;
    while (cin >> n >> m >> r && n != 0 && m != 0 && r != 0) {
        vector<int> A(n), B(m);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }
        
        vector<vector<int>> rules(r);
        for (int i = 0; i < r; ++i) {
            int k;
            cin >> k;
            rules[i].resize(k + 1);
            for (int j = 0; j < k + 1; ++j) {
                cin >> rules[i][j];
            }
        }
        
        if (A == B) {
            cout << n << endl;
        } else if (equalAfterTransform(A, B, rules)) {
            cout << "1" << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}