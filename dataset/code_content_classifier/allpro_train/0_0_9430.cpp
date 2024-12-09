#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i];
    }

    for (int baton = 1; baton <= M; baton++) {
        for (int i = 0; i < N - 1; i++) {
            if (students[i] % baton > students[i + 1] % baton) {
                swap(students[i], students[i + 1]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << students[i] << endl;
    }

    return 0;
}