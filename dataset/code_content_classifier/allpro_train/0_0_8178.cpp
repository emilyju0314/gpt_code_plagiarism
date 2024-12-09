#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Calculate the probability of the trick being successful
    double success_prob;
    if (n == 1) {
        success_prob = 1.0;
    } else {
        double same_card_prob = 1.0 / m;
        double diff_card_prob = 1.0 - same_card_prob;
        success_prob = same_card_prob + (diff_card_prob * (1.0 / n));
    }

    cout << fixed << setprecision(16) << success_prob << endl;

    return 0;
}