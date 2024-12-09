#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

struct Ball {
    Point position;
    int dx, dy, score;
};

struct Participant {
    Point position;
};

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calculateProbability(double distance, double speed) {
    return 1 / speed / distance;
}

int main() {
    int N, M;

    while (true) {
        std::cin >> N >> M;
        
        if (N == 0 && M == 0) break;

        std::vector<Participant> participants(N);
        std::vector<Ball> balls(M);

        for (int i = 0; i < N; i++) {
            std::cin >> participants[i].position.x >> participants[i].position.y;
        }

        for (int i = 0; i < M; i++) {
            std::cin >> balls[i].position.x >> balls[i].position.y >> balls[i].dx >> balls[i].dy >> balls[i].score;
        }

        double totalExpectedScore = 0.0;
        double maxExpectedScore = 0.0;

        for (const Ball& ball : balls) {
            double expectedScore = 0.0;

            for (const Participant& participant : participants) {
                double minDistance = std::numeric_limits<double>::infinity();

                for (int x = ball.position.x - ball.dx; x <= ball.position.x + ball.dx; x++) {
                    for (int y = ball.position.y - ball.dy; y <= ball.position.y + ball.dy; y++) {
                        Point ballPosition = {x, y};
                        double distance = calculateDistance(participant.position, ballPosition);

                        minDistance = std::min(minDistance, distance);
                    }
                }

                double probability = calculateProbability(minDistance, 1.0);
                expectedScore += probability * ball.score;
            }

            totalExpectedScore += expectedScore;
            maxExpectedScore = std::max(maxExpectedScore, expectedScore);
        }

        std::cout << totalExpectedScore / N << std::endl;
    }

    return 0;
}