#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dishes(N);
    for (int i = 0; i < N; i++) {
        cin >> dishes[i];
    }

    double expected = 0.0;
    for (int i = 0; i < N; i++) {
        double prob = 1.0;
        int total_sushi = 0;

        for (int j = 0; j < N; j++) {
            total_sushi += dishes[j];
        }

        while (total_sushi > 0) {
            double p = (double)dishes[i] / total_sushi;
            expected += prob * (1.0 / p);
            prob *= p;
            total_sushi--;
        }
    }

    cout << expected << endl;

    return 0;
}