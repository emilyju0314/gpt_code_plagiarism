#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> board(n);
        for(int i = 0; i < n; i++) {
            board[i] = i+1;
        }

        int minNum = 0;
        vector<pair<int, int>> operations;
        
        while(board.size() > 1) {
            int a = *min_element(board.begin(), board.end());
            int index_a = min_element(board.begin(), board.end()) - board.begin();
            board.erase(board.begin() + index_a);

            int b = *min_element(board.begin(), board.end());
            int index_b = min_element(board.begin(), board.end()) - board.begin();
            board.erase(board.begin() + index_b);

            minNum = max((a+b+1)/2, minNum);
            board.push_back((a+b+1)/2);
            operations.push_back({a, b});
        }

        cout << minNum << endl;
        for(auto operation : operations) {
            cout << operation.first << " " << operation.second << endl;
        }
    }

    return 0;
}