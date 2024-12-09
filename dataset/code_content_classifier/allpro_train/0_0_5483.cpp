#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    int mistakes = 0;
    vector<char> operations;

    for(int i = 0; i <= n; i++) {
        int x = 0;
        int y = i;
        x = (r - y) / (i + 1);
        if (x < 0 || x > 1) {
            continue;
        }
        if (x == 1 && (r - y) % (i + 1) == 0) {
            mistakes = i;
            for(int j = 1; j <= mistakes; j++) {
                operations.push_back('T');
            }
            for(int j = mistakes + 1; j <= n; j++) {
                operations.push_back('B');
            }
            break;
        }
    }

    if (mistakes == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << mistakes << endl;
        for(char op : operations) {
            cout << op;
        }
        cout << endl;
    }

    return 0;
}