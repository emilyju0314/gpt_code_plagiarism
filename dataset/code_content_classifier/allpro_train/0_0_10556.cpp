#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> dice_faces = {1, 2, 3, 4, 5, 6};

bool check_pair(int a, int b) {
    return a + b == 7;
}

bool check_config(vector<vector<int>>& top, vector<vector<int>>& front, vector<vector<int>>& right) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (top[i][j] != 0 && front[i][j] != 0) {
                bool found = false;
                for (int face : dice_faces) {
                    if (check_pair(face, top[i][j]) && check_pair(face, front[i][j])) {
                        right[i][j] = face;
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
        }
    }
    return true;
}

void generate_config(vector<vector<int>>& top, vector<vector<int>>& front, vector<vector<int>>& right) {
    do {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                right[i][j] = 0;
            }
        }
    } while (!check_config(top, front, right));
}

int main() {
    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        vector<vector<int>> top(3, vector<int>(3));
        vector<vector<int>> front(3, vector<int>(3));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> top[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> front[i][j];
            }
        }

        vector<vector<int>> right(3, vector<int>(3));
        generate_config(top, front, right);

        set<int> sums;
        do {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += right[i][j];
                }
            }
            sums.insert(sum);
        } while (next_permutation(dice_faces.begin(), dice_faces.end()));

        for (int s : sums) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}