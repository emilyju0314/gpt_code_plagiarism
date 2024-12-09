#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Vector {
    int x, y, z;
    Vector(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct Mine {
    Vector center;
    int radius;
    vector<Vector> spikes;
    Mine(Vector center, int radius, vector<Vector> spikes) : center(center), radius(radius), spikes(spikes) {}
};

struct DeathStar {
    Vector position;
    Vector direction;
    int radius;
    DeathStar(Vector position, Vector direction, int radius) : position(position), direction(direction), radius(radius) {}
};

double dotProduct(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double distance(Vector v1, Vector v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

double timeToExplode(Mine mine, DeathStar star) {
    double maxSpikesLength = 0;
    for(Vector spike : mine.spikes) {
        double spikeLength = distance(spike, Vector(0, 0, 0));
        if(spikeLength > maxSpikesLength) {
            maxSpikesLength = spikeLength;
        }
    }

    double starToMineCenter = distance(star.position, mine.center);
    double timeToHitCenter = starToMineCenter - star.radius - mine.radius;
    double timeToHitSpikes = starToMineCenter - star.radius - maxSpikesLength;

    if(timeToHitCenter < 0 || timeToHitSpikes < 0) {
        return -1;
    }

    return min(timeToHitCenter, timeToHitSpikes) / dotProduct(star.direction, star.direction);
}

int main() {
    int Ax, Ay, Az, vx, vy, vz, R;
    cin >> Ax >> Ay >> Az >> vx >> vy >> vz >> R;

    Vector starPosition(Ax, Ay, Az);
    Vector starDirection(vx, vy, vz);
    DeathStar star(starPosition, starDirection, R);

    int n;
    cin >> n;

    vector<Mine> mines;
    for(int i = 0; i < n; i++) {
        int Oix, Oiy, Oiz, ri, mi;
        cin >> Oix >> Oiy >> Oiz >> ri >> mi;

        Vector center(Oix, Oiy, Oiz);
        vector<Vector> spikes;
        for(int j = 0; j < mi; j++) {
            int pijx, pijy, pijz;
            cin >> pijx >> pijy >> pijz;
            Vector spike(pijx, pijy, pijz);
            spikes.push_back(spike);
        }

        Mine mine(center, ri, spikes);
        mines.push_back(mine);
    }

    double minBlastTime = -1;
    for(Mine mine : mines) {
        double time = timeToExplode(mine, star);
        if(time != -1) {
            if(minBlastTime == -1 || time < minBlastTime) {
                minBlastTime = time;
            }
        }
    }

    cout << minBlastTime << endl;

    return 0;
}