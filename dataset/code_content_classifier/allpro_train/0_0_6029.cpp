#include <iostream>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    int *sheets = new int[n];
    for (int i = 0; i < n; i++) {
        sheets[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int pi;
        cin >> pi;

        int min_sheet = 1;
        for (int j = 1; j < n; j++) {
            if (sheets[j] < sheets[min_sheet]) {
                min_sheet = j;
            }
        }

        sheets[min_sheet] = pi;
        cout << (min_sheet + 1) << endl;
        cout << flush;

        bool finished = true;
        for (int j = 0; j < n - 1; j++) {
            if (sheets[j] > sheets[j + 1]) {
                finished = false;
                break;
            }
        }

        if (finished) {
            break;
        }
    }

    delete[] sheets;

    return 0;
}