#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cells(N);
    for (int i = 0; i < N; i++) {
        cin >> cells[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int cell = i;
        vector<bool> visited(N, false);

        while (true) {
            if (visited[cell]) {
                break;
            }
            visited[cell] = true;
            cell = (cell + cells[cell]) % N;
            if (cell == i) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}