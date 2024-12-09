#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N;

    vector<vector<int>> adjMatrix(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<int> values(N);
    for(int i = 0; i < N; i++) {
        cin >> values[i];
    }

    cin >> T;

    vector<int> nextValues = values;
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < N; i++) {
            int count = 0;
            for(int j = 0; j < N; j++) {
                if(adjMatrix[i][j] == 1 && values[j] == 1) {
                    count++;
                }
            }
            nextValues[i] = count % 2;
        }
        values = nextValues;
    }

    // Check for consistency
    bool consistent = true;
    for(int i = 0; i < N; i++) {
        int count = 0;
        for(int j = 0; j < N; j++) {
            if(adjMatrix[i][j] == 1 && nextValues[j] == 1) {
                count++;
            }
        }
        if(values[i] != count % 2) {
            consistent = false;
            break;
        }
    }

    // Check for uniqueness
    bool unique = true;
    for(int i = 0; i < N; i++) {
        int count = 0;
        for(int j = 0; j < N; j++) {
            if(adjMatrix[i][j] == 1 && nextValues[j] == 1) {
                count++;
            }
        }
        if(nextValues[i] != count % 2) {
            unique = false;
            break;
        }
    }

    if(!consistent) {
        cout << "none" << endl;
    } else if(!unique) {
        cout << "ambiguous" << endl;
    } else {
        for(int i = 0; i < N; i++) {
            cout << nextValues[i] << " ";
        }
        cout << endl;
    }

    return 0;
}