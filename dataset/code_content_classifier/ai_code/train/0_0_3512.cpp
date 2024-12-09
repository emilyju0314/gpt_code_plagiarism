#include <iostream>

using namespace std;

int main() {
    long long d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    if (d <= k) {
        cout << d * a << endl;
        return 0;
    }

    long long time = 0;
    long long distance_left = d;
    long long breaks_needed = (d - 1) / k; // Number of times car will break

    if (a * k + t <= b * k) {
        // It's faster to drive the whole way without walking
        time = a * d;
    } else {
        time = a * k + t; // Drive the first k kilometers
        distance_left -= k;

        if (a * k + t <= b * k) {
            // It's faster to drive the remaining distance without walking
            time += distance_left * a;
        } else {
            // Drive as far as possible until the next break and walk the rest
            time += k * a; // Drive to the next break
            distance_left -= k;

            while (distance_left > 0) {
                if (distance_left <= k) {
                    time += distance_left * a;
                } else {
                    time += a * k + t;
                    distance_left -= k;
                }
            }
        }
    }

    cout << time << endl;
    return 0;
}