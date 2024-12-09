#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printCarpetLayout(int N, vector<string>& carpetLayout) {
    for (int i = 0; i < N; i++) {
        cout << carpetLayout[i] << endl;
    }
}

bool isValidLayout(int N, vector<string>& carpetLayout) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (carpetLayout[i][j] == carpetLayout[i][j + 1] && carpetLayout[i][j] == carpetLayout[i][j + 2]) {
                return false;
            }
        }
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 2; i++) {
            if (carpetLayout[i][j] == carpetLayout[i + 1][j] && carpetLayout[i][j] == carpetLayout[i + 2][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, K;
    int caseNum = 1;

    while (true) {
        cin >> N >> K;

        if (N == 0 && K == 0) {
            break;
        }
        
        vector<string> carpetLayout(N, string(N, '.'));

        vector<int> dirs = {0, 1, 2, 3};

        do {
            int k = 1;
            do {
                bool isValid = isValidLayout(N, carpetLayout);
                if (isValid && k == K) {
                    printCarpetLayout(N, carpetLayout);
                    cout << endl;
                }
                k++;
                next_permutation(carpetLayout.begin(), carpetLayout.end());
            } while (next_permutation(dirs.begin(), dirs.end()));

        } while (next_permutation(carpetLayout.begin(), carpetLayout.end()));

        if (k < K) {
            cout << "No" << endl;
        }

        cout << endl;
    }

    return 0;
}