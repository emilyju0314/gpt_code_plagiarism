#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Constraint {
    int a, b, d;
    char o, s;
};

int main() {
    int N, C;
    cin >> N >> C;

    vector<Constraint> constraints(C);
    for (int i = 0; i < C; i++) {
        cin >> constraints[i].a >> constraints[i].b >> constraints[i].o >> constraints[i].s >> constraints[i].d;
    }

    int max_distance = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                bool valid = true;

                for (const auto& constraint : constraints) {
                    if (constraint.o == '<' && (i >= j)) {
                        valid = false;
                        break;
                    }
                    if (constraint.o == '>' && (i <= j)) {
                        valid = false;
                        break;
                    }
                    if (constraint.o == '*' && (i == j || (i < j && constraint.s == '+' && abs(i - j) < constraint.d) || (i > j && constraint.s == '-' && abs(i - j) > constraint.d))) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    max_distance = max(max_distance, abs(i - j));
                }
            }
        }
    }

    if (max_distance == N) {
        cout << "inf" << endl;
    } else if (max_distance == 0) {
        cout << "-1" << endl;
    } else {
        cout << max_distance << endl;
    }

    return 0;
}