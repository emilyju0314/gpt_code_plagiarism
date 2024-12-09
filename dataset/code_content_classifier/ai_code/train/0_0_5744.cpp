#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence = {0};
    double sum = 0;
    double num_elements = 1;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, x;
            cin >> a >> x;

            sum += a * x;
            num_elements += a;

            for (int j = 0; j < a; j++) {
                sum += x;
                sequence[j] += x;
            }
        } else if (t == 2) {
            int k;
            cin >> k;

            sum += k;
            num_elements++;
            sequence.push_back(k);
        } else {
            sum -= sequence.back();
            num_elements--;

            sequence.pop_back();
        }

        cout << fixed << setprecision(6) << sum / num_elements << endl;
    }

    return 0;
}