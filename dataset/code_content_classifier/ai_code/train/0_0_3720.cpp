#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Lock {
    int position;
    int volume;
    int max_water_injection;
    int max_drainage;
    bool west_to_east; // 0 for east higher than west, 1 for east lower than west
};

struct Ship {
    int speed;
    double time_passed;
};

int main() {
    int N, M, K;
    
    while (true) {
        cin >> N >> M >> K;
        
        if (N == 0 && M == 0 && K == 0) {
            break;
        }
        
        vector<Lock> locks(N);
        vector<Ship> ships(M);
        
        for (int i = 0; i < N; i++) {
            cin >> locks[i].position >> locks[i].volume >> locks[i].max_water_injection >> locks[i].max_drainage >> locks[i].west_to_east;
        }
        
        for (int i = 0; i < M; i++) {
            cin >> ships[i].speed;
            ships[i].time_passed = 0;
        }
        
        double total_time = 0;
        
        for (int i = 0; i < M; i++) {
            int current_position = 0;
            double current_time = 0;
            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
            
            while (current_position < K) {
                double time_to_move = (double)1 / ships[i].speed;
                pq.push({current_time + time_to_move, i});
                current_time -= current_time;
                
                while (!pq.empty()) {
                    pair<double, int> top_ship = pq.top();
                    pq.pop();
                    
                    int ship_idx = top_ship.second;
                    double ship_time = top_ship.first;
                    
                    if (ship_idx != i) {
                        current_time = ship_time - time_to_move;
                        break;
                    }
                    
                    double time_needed = 0;
                    for (int j = 0; j < N; j++) {
                        int lock_position = locks[j].position;
                        
                        if (lock_position >= current_position) {
                            double water_needed = locks[j].volume;
                            double water_in_lock = 0;
                            
                            time_needed = max(time_needed, (water_needed - water_in_lock) / locks[j].max_water_injection);
                        } else {
                            double water_in_lock = locks[j].volume;
                            
                            if (locks[j].west_to_east) {
                                time_needed = max(time_needed, water_in_lock / locks[j].max_drainage);
                            }
                        }
                    }
                    
                    current_time = ship_time + time_needed;
                    current_position = min(K, current_position + ships[ship_idx].speed * time_needed);
                }
            }
            
            total_time = max(total_time, current_time);
        }
        
        cout << setprecision(10) << total_time << endl;
    }
    
    return 0;
}