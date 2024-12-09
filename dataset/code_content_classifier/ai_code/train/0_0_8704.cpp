#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n, 0);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = 0; j < 3; j++) {
            if ((j == 0 && a > 0) || (j == 1 && b > 0) || (j == 2 && c > 0)) {
                int k = (j == 0) ? a : (j == 1) ? b : c;

                if (k < 0) {
                    int problem_score = 500;
                    if (2 * n < -2 * k) problem_score = 1000;
                    if (4 * n < -2 * k) problem_score = 1500;
                    if (8 * n < -2 * k) problem_score = 2000;
                    if (16 * n < -2 * k) problem_score = 2500;
                    if (32 * n < -2 * k) problem_score = 3000;

                    scores[i] += problem_score + (j == 0 ? 100 : 0);
                }
            }
        }
    }

    int my_score = scores[0];

    int result = 1;
    for (int i = 1; i < n; i++) {
        if (scores[i] > my_score) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}