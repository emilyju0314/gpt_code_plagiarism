#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> difficulties(N);
    for (int i = 0; i < N; i++) {
        cin >> difficulties[i];
    }

    int total_problems = 0;
    for (int i = 0; i < N; i++) {
        if (difficulties[i] % 2 == 0) {
            total_problems++;
        } else {
            total_problems--;
        }
    }

    if (total_problems != 0) {
        cout << "0" << endl;
        return 0;
    }

    int K = N / 2;
    int count = 0;
    int arcs = 0;
    int abcs = 0;
    for (int i = 0; i < N; i++) {
        if (i < K) {
            if (difficulties[i] % 2 == 0) {
                arcs++;
            } else {
                abcs++;
            }
        } else {
            if (difficulties[i] % 2 == 0) {
                arcs--;
            } else {
                abcs--;
            }
        }
        if (arcs == abcs) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}