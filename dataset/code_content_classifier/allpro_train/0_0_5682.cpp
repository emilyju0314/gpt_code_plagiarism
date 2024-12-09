#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    // Calculate the maximum number of winners
    long long max_winners = min(n/2, n/(k+1));

    // Calculate the number of students with diplomas, certificates, and who are not winners
    long long diplomas = max_winners/(k+1);
    long long certificates = max_winners - diplomas;
    long long not_winners = n - max_winners;

    cout << diplomas << " " << certificates << " " << not_winners << endl;

    return 0;
}