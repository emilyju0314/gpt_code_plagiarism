#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string recipe;
    int nb, ns, nc;
    int pb, ps, pc;
    long long r;

    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    int countB = count(recipe.begin(), recipe.end(), 'B');
    int countS = count(recipe.begin(), recipe.end(), 'S');
    int countC = count(recipe.begin(), recipe.end(), 'C');

    long long low = 0;
    long long high = 1e13;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        long long neededB = max(0LL, mid * countB - nb);
        long long neededS = max(0LL, mid * countS - ns);
        long long neededC = max(0LL, mid * countC - nc);

        long long cost = neededB * pb + neededS * ps + neededC * pc;
        
        if (cost <= r) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}