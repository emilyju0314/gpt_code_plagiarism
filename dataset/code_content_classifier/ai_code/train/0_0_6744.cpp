#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) break;

        map<string, int> timestamp;
        map<string, int> duration;

        vector<string> start_time;
        vector<string> start_visitor;

        for (int i = 0; i < n; i++) {
            string date, time, io, visitor;
            cin >> date >> time >> io >> visitor;

            string key = date + " " + time;

            if (io == "I") {
                timestamp[visitor] = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
                start_time.push_back(key);
                start_visitor.push_back(visitor);
            } else {
                int start = timestamp[visitor];
                int end = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
                
                for (int j = 0; j < start_time.size(); j++) {
                    if (start_visitor[j] == visitor) {
                        duration[visitor] += end - start;
                        start_time.erase(start_time.begin() + j);
                        start_visitor.erase(start_visitor.begin() + j);
                        break;
                    }
                }
            }
        }

        int max_duration = 0;
        for (auto it = duration.begin(); it != duration.end(); it++) {
            if (it->first != "000" && it->second > max_duration) {
                max_duration = it->second;
            }
        }

        cout << max_duration << endl;
    }

    return 0;
}