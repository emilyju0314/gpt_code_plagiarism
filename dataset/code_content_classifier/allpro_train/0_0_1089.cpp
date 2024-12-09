#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> frogs(n);

    vector<int> board(m+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> frogs[i].first >> frogs[i].second;
        board[frogs[i].first] = i + 1;
    }

    vector<int> remaining_frogs(n, 1);

    int num_remaining = n;

    int current_frog = 0;
    while(num_remaining > 1) {
        int cur_cell = frogs[current_frog].first;
        int jump_length = frogs[current_frog].second;

        int knocked_out = 0;
        for(int i = 1; i <= jump_length; i++) {
            cur_cell = (cur_cell % m) + 1;
            if(board[cur_cell] != 0 && remaining_frogs[board[cur_cell]-1] == 1) {
                knocked_out++;
                remaining_frogs[board[cur_cell]-1] = 0;
                num_remaining--;
            }
        }

        if(knocked_out == 0) {
            remaining_frogs[current_frog] = 0;
            num_remaining--;
        }

        current_frog = (current_frog + 1) % n;
    }

    cout << num_remaining << endl;
    for(int i = 0; i < n; i++) {
        if(remaining_frogs[i] == 1) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}