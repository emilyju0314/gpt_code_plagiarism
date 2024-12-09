#include <iostream>
#include <vector>
#include <algorithm>

struct Board {
    int position;
    int height;
};

struct Faucet {
    int position;
    int flowRate;
};

int main() {
    int numDataSets;
    std::cin >> numDataSets;

    for (int d = 0; d < numDataSets; ++d) {
        int N;
        std::cin >> N;

        std::vector<Board> boards(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> boards[i].position >> boards[i].height;
        }

        int M;
        std::cin >> M;

        std::vector<Faucet> faucets(M);
        for (int i = 0; i < M; ++i) {
            std::cin >> faucets[i].position >> faucets[i].flowRate;
        }

        int L;
        std::cin >> L;

        for (int i = 0; i < L; ++i) {
            int P;
            std::cin >> P;

            double totalTime = 0;
            double waterLevel = 0;

            // Simulate water flow
            while (waterLevel < 50.0) {
                double minTimeToNextEvent = 1e9; // Set to a large value
                for (const auto& board : boards) {
                    if (board.position != P) {
                        double timeToNextEvent = (50.0 - waterLevel) / 100.0; // Time to reach height of 50 cm
                        minTimeToNextEvent = std::min(minTimeToNextEvent, timeToNextEvent);
                    }
                }

                for (const auto& faucet : faucets) {
                    double timeToNextEvent = (50.0 - waterLevel) / faucet.flowRate;
                    minTimeToNextEvent = std::min(minTimeToNextEvent, timeToNextEvent);
                }

                // Update water level
                waterLevel += minTimeToNextEvent * faucets.size(); // Water flow from each faucet
                totalTime += minTimeToNextEvent;

                // Update water level due to boards
                for (const auto& board : boards) {
                    if (board.position < P && board.height > waterLevel) {
                        waterLevel = board.height;
                    }
                }
            }

            std::cout << std::fixed;
            std::cout.precision(6);
            std::cout << waterLevel << std::endl;
        }
    }

    return 0;
}