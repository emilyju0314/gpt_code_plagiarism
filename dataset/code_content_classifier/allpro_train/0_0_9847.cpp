#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Car {
    int house;
    long long available_time;
    int car_number;

    Car(int house, long long available_time, int car_number) : house(house), available_time(available_time), car_number(car_number) {}

    bool operator<(const Car& other) const {
        if (house == other.house) {
            return car_number > other.car_number;
        }
        return house > other.house;
    }
};

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> initial_positions(k);
    for (int i = 0; i < k; i++) {
        cin >> initial_positions[i];
    }

    vector<Car> cars;
    for (int i = 0; i < k; i++) {
        cars.push_back(Car(initial_positions[i], 0, i+1));
    }

    priority_queue<Car> pq;

    for (int i = 0; i < m; i++) {
        long long t, a, b;
        cin >> t >> a >> b;

        while (!pq.empty() && pq.top().available_time <= t) {
            cars.push_back(pq.top());
            pq.pop();
        }

        int min_wait_time = INT_MAX;
        int assigned_car = -1;

        for (int j = 0; j < cars.size(); j++) {
            int wait_time = max(cars[j].available_time, t) - t + abs(cars[j].house - a);
            if (wait_time < min_wait_time) {
                min_wait_time = wait_time;
                assigned_car = cars[j].car_number;
            }
        }

        cout << assigned_car << " " << min_wait_time << endl;

        int drop_off_time = min_wait_time + abs(a - b) + t;
        pq.push(Car(b, drop_off_time, assigned_car));

        cars.erase(remove_if(cars.begin(), cars.end(), 
            [&](const Car& car){ return car.car_number == assigned_car; }), cars.end());
    }

    return 0;
}