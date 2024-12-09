#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<vector<int>> graph;
        int number;
        while (cin >> number) {
            if (number == 0) {
                break;
            }
            vector<int> record;
            int counter = 0;
            stack<int> rooms;
            rooms.push(0);
            record.push_back(1);
            
            while (!rooms.empty()) {
                int current_room = rooms.top();
                rooms.pop();
                
                for (int j = 0; j < abs(number); j++) {
                    int next_room;
                    cin >> next_room;
                    record.push_back(next_room);
                    if (number < 0) {
                        counter--;
                    } else {
                        counter++;
                        rooms.push(next_room - 1);
                    }
                }
            }
            graph.push_back(record);
        }
        
        for (int j = 0; j < graph.size(); j++) {
            cout << j + 1;
            for (int k = 1; k < graph[j].size(); k++) {
                cout << " " << graph[j][k];
            }
            cout << endl;
        }
    }

    return 0;
}