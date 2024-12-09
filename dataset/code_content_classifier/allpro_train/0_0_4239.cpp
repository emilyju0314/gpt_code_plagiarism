#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Letter {
    string mark;
    int index;
};

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        
        vector<Letter> letters(N);
        map<string, vector<int>> jumps;
        
        for (int i = 0; i < N; i++) {
            cin >> letters[i].mark;
            letters[i].index = i + 1;
            if (letters[i].mark.back() == 'v') {
                letters[i].mark.pop_back();
            } else {
                jumps[letters[i].mark].push_back(i);
            }
        }
        
        int next = 0;
        for (int i = 0; i < N; i++) {
            if (letters[i].mark == "v") {
                next = i;
                cout << letters[i].index << endl;
                break;
            }
        }
        
        while (next < N) {
            cout << letters[next].index << endl;
            if (next + 1 < N && letters[next+1].mark == "v") {
                next++;
            } else {
                string jump = letters[next].mark;
                if (!jumps[jump].empty()) {
                    next = jumps[jump].back();
                    jumps[jump].pop_back();
                } else {
                    next++;
                }
            }
        }
    }

    return 0;
}