#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y, t;
};

struct Obstacle {
    int sx, sy, tx, ty;
};

int main() {
    int Time, R;
    while (std::cin >> Time >> R && (Time != 0 || R != 0)) {
        int L, M, N;
        std::cin >> L;
        std::vector<Point> maryMoves(L);
        for (int i = 0; i < L; i++) {
            std::cin >> maryMoves[i].x >> maryMoves[i].y >> maryMoves[i].t;
        }
        std::cin >> M;
        std::vector<Point> georgeMoves(M);
        for (int i = 0; i < M; i++) {
            std::cin >> georgeMoves[i].x >> georgeMoves[i].y >> georgeMoves[i].t;
        }
        std::cin >> N;
        std::vector<Obstacle> obstacles(N);
        for (int i = 0; i < N; i++) {
            std::cin >> obstacles[i].sx >> obstacles[i].sy >> obstacles[i].tx >> obstacles[i].ty;
        }

        double totalTimeInSight = 0.0;
        for (int t = 1; t <= Time; t++) {
            double maryX, maryY, georgeX, georgeY;
            for (int i = 0; i < L - 1; i++) {
                if (t >= maryMoves[i].t && t < maryMoves[i + 1].t) {
                    double ratio = static_cast<double>(t - maryMoves[i].t) / (maryMoves[i + 1].t - maryMoves[i].t);
                    maryX = maryMoves[i].x + (maryMoves[i + 1].x - maryMoves[i].x) * ratio;
                    maryY = maryMoves[i].y + (maryMoves[i + 1].y - maryMoves[i].y) * ratio;
                    break;
                }
            }
            for (int i = 0; i < M - 1; i++) {
                if (t >= georgeMoves[i].t && t < georgeMoves[i + 1].t) {
                    double ratio = static_cast<double>(t - georgeMoves[i].t) / (georgeMoves[i + 1].t - georgeMoves[i].t);
                    georgeX = georgeMoves[i].x + (georgeMoves[i + 1].x - georgeMoves[i].x) * ratio;
                    georgeY = georgeMoves[i].y + (georgeMoves[i + 1].y - georgeMoves[i].y) * ratio;
                    break;
                }
            }
            bool inSight = false;
            for (int i = 0; i < N; i++) {
                if (maryX >= obstacles[i].sx && maryX <= obstacles[i].tx && maryY >= obstacles[i].sy && maryY <= obstacles[i].ty) {
                    inSight = false;
                    break;
                }
            }
            double distance = sqrt(pow(georgeX - maryX, 2) + pow(georgeY - maryY, 2));
            double angle = atan2(georgeY - maryY, georgeX - maryX) * 180.0 / M_PI;
            if (distance <= R && abs(angle) <= 45) {
                inSight = true;
            }
            if (inSight) {
                totalTimeInSight += 1.0;
            }
        }

        std::cout << std::fixed;
        std::cout.precision(4);
        std::cout << totalTimeInSight << std::endl;
    }

    return 0;
}