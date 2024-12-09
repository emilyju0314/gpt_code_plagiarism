#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;

    int size = pow(3, N);
    vector<int> positions(size);

    for (int i = 0; i < size; i++) {
        positions[i] = i;
    }

    for (char c : T) {
        if (c == 'S') {
            for (int i = 0; i < size; i++) {
                string str = to_string(positions[i]);
                for (char &digit : str) {
                    if (digit == '1') {
                        digit = '2';
                    } else if (digit == '2') {
                        digit = '1';
                    }
                }
                positions[i] = stoi(str);
            }
        } else {
            for (int i = 0; i < size; i++) {
                positions[i] = (positions[i] + 1) % size;
            }
        }
    }

    for (int p : positions) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}