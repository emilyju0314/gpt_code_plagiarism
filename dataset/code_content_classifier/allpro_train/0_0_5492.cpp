#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int g[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> g[i][j];
        }
    }

    int total_max_happiness = 0;
    int students[] = {1, 2, 3, 4, 5};
    
    do {
        int current_happiness = 0;
        for (int i = 0; i < 5; i += 2) {
            current_happiness += g[students[i] - 1][students[i + 1] - 1] + g[students[i + 1] - 1][students[i] - 1];
        }

        total_max_happiness = max(total_max_happiness, current_happiness);
    } while (next_permutation(students, students + 5));

    cout << total_max_happiness << endl;

    return 0;
}