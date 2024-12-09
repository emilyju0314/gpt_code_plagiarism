#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end());

    int jeff_moves = 0;
    int furik_moves = 0;
    double expected_moves = 0.0;

    while (p != sorted_p) {
        if (jeff_moves % 2 == 0) {
            jeff_moves++;
            for (int i = 0; i < n - 1; i++) {
                if (p[i] > p[i + 1]) {
                    swap(p[i], p[i + 1]);
                }
            }
        } else {
            furik_moves++;
            int head_moves = 0;
            int tail_moves = 0;
            for (int i = 0; i < n - 1; i++) {
                if (p[i] > p[i + 1]) {
                    head_moves++;
                } else if (p[i] < p[i + 1]) {
                    tail_moves++;
                }
            }
            if (head_moves > 0 && tail_moves > 0) {
                if (rand() % 2 == 0) {
                    for (int i = 0; i < n - 1; i++) {
                        if (p[i] > p[i + 1]) {
                            swap(p[i], p[i + 1]);
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        if (p[i] < p[i + 1]) {
                            swap(p[i], p[i + 1]);
                            break;
                        }
                    }
                }
            } else if (head_moves == 0) {
                for (int i = 0; i < n - 1; i++) {
                    if (p[i] < p[i + 1]) {
                        swap(p[i], p[i + 1]);
                        break;
                    }
                }
            } else if (tail_moves == 0) {
                for (int i = 0; i < n - 1; i++) {
                    if (p[i] > p[i + 1]) {
                        swap(p[i], p[i + 1]);
                        break;
                    }
                }
            }
        }
        expected_moves += 1.0;
    }
    
    cout << fixed << expected_moves << endl;

    return 0;
}