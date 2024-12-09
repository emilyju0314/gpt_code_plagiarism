#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int kmin, kmax;

    // Calculate kmin
    int maxInTeam = n / m;
    int remainingParticipants = n % m;
    kmin = remainingParticipants * (maxInTeam + 1) * maxInTeam / 2;
    kmin += (m - remainingParticipants) * maxInTeam * (maxInTeam - 1) / 2;

    // Calculate kmax
    kmax = (n - m + 1) * (n - m) / 2;

    std::cout << kmin << " " << kmax << std::endl;

    return 0;
}