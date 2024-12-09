#include <iostream>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;

    long long full_cooking_time = t * 2;
    long long remaining_time = (k + d - 1) / d * d - k;
    long long total_cycles = (full_cooking_time + remaining_time - 1) / full_cooking_time;
    
    long long total_time = total_cycles * full_cooking_time;
    total_time += min(remaining_time, t);

    cout << fixed;
    cout.precision(9);
    cout << total_time << endl;

    return 0;
}