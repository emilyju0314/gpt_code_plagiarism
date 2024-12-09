#include <iostream>
#include <iomanip>

using namespace std;

double calculateExpectedRaces(double c, double m, double p, double v) {
    double races = p; // Probability of drawing Pink Slip without playing any races

    // Iterate through each possibility and calculate their probabilities
    while (c > 1e-9 || m > 1e-9) {
        double cp = min(c, v);
        double mp = min(m, v);

        // Calculate the expected number of races using the current probabilities
        races += (cp + mp) * (1 + calculateExpectedRaces((c - cp) / (1 - cp), (m - mp) / (1 - mp), p, v));

        // Update probabilities for the next iteration
        double sum = cp + mp;
        c = (1 - cp) * c / (1 - sum);
        m = (1 - mp) * m / (1 - sum);
    }

    return races;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        double c, m, p, v;
        cin >> c >> m >> p >> v;

        double expectedRaces = calculateExpectedRaces(c, m, p, v);
        cout << fixed << setprecision(12) << expectedRaces << endl;
    }

    return 0;
}