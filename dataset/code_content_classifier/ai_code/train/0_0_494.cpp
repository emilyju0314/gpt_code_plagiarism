#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    vector<int> doors(2 * N);
    vector<int> colors(N);

    int color = 1;
    int door_count = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (s[i] == '1') {
            if (door_count == 0) {
                colors[color - 1] = i + 1;
            } else {
                doors[i] = colors[color - 1];
            }
            door_count = (door_count + 1) % 2;
        } else {
            doors[i] = color;
            doors[i+1] = color;
            i++;
            color++;
        }
    }

    for (int i = 0; i < 2 * N; i++) {
        if (doors[i] == 0) {
            doors[i] = color;
        }
    }

    bool valid = true;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (abs(doors[i] - doors[i+1]) != 1) {
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * N; i++) {
            cout << doors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}