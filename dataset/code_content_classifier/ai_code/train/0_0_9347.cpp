#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Device {
    int floor;
    int speed;
    int stopTime;
    int position;
};

struct Elevator {
    int capacity;
    int speed;
    int stopTime;
    int position;
    int time;
    vector<Device> devices;
};

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        int d;
        cin >> d;

        vector<int> devicesOnFloor(N, 0);

        for (int i = 0; i < N; i++) {
            int numDevices;
            cin >> numDevices;
            devicesOnFloor[i] = numDevices;
        }

        vector<Elevator> elevators(M);

        for (int i = 0; i < M; i++) {
            cin >> elevators[i].capacity >> elevators[i].speed >> elevators[i].stopTime >> elevators[i].position;
            elevators[i].time = 0;
        }

        int k, tx, ty, tz;
        cin >> k >> tx >> ty >> tz;

        while (true) {
            bool evacuated = false;
            for (int i = M - 1; i >= 0; i--) {
                if (!elevators[i].devices.empty() && elevators[i].position == k) {
                    for (Device &device : elevators[i].devices) {
                        if (k == 1) {
                            evacuated = true;
                            break;
                        }
                        devicesOnFloor[k - 1]++;
                    }
                    elevators[i].devices.clear();
                }
            }
            if (evacuated) break;

            for (int i = 0; i < N; i++) {
                if (devicesOnFloor[i] > 0) {
                    for (Elevator &elevator : elevators) {
                        if (elevator.time == 0) {
                            elevator.time += abs(elevator.position - (i + 1)) * 2 * elevator.stopTime;
                            elevator.position = i + 1;
                            for (int j = 0; j < min(elevator.capacity, devicesOnFloor[i]); j++) {
                                Device device;
                                device.floor = i + 1;
                                device.speed = elevator.speed;
                                device.stopTime = elevator.stopTime;
                                device.position = elevator.position;
                                elevator.devices.push_back(device);
                                devicesOnFloor[i]--;
                            }
                        }
                    }
                }
            }

            for (Elevator &elevator : elevators) {
                if (elevator.time > 0 && elevator.devices.size() > 0) {
                    int destination = min_element(elevator.devices.begin(), elevator.devices.end(),
                        [&](const Device &a, const Device &b) {
                            return a.floor > b.floor;
                    })->floor;
                    bool burn = false;
                    for (int i = tz; i > 0; i--) {
                        if (destination == k + d*i) {
                            burn = true;
                            break;
                        }
                    }
                    if (burn) {
                        elevator.position = k;
                        elevator.time = 0;
                        elevator.devices.clear();
                    }
                    else {
                        elevator.time += abs(elevator.position - destination) * 2 * elevator.stopTime;
                        elevator.position = destination;
                    }
                }
            }
        }

        int totalEvacuated = 0;
        double time = 0.0;
        for (Elevator &elevator : elevators) {
            totalEvacuated += elevator.devices.size();
            if (elevator.devices.size() > 0) {
                time = elevator.time + abs(elevator.position - 1) * 2 * elevator.stopTime;
            }
        }

        cout << totalEvacuated << " " << fixed << setprecision(3) << time << endl;
    }

    return 0;
}