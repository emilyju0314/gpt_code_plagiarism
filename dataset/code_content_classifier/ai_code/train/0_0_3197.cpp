#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, long long>> sun_members, moon_members;
    
    for(int i = 0; i < N; i++) {
        int O, P;
        cin >> O >> P;
        
        if(P > 0) {
            sun_members.push_back({O, P});
        } else {
            moon_members.push_back({O, P});
        }
    }
    
    sort(sun_members.begin(), sun_members.end(), greater<pair<int, long long>>());
    sort(moon_members.begin(), moon_members.end(), greater<pair<int, long long>>());
    
    long long sun_power = 0, moon_power = 0;
    for(auto& member : sun_members) {
        sun_power += (long long) member.first * member.second;
    }
    
    vector<long long> p_values;
    for(auto& member : moon_members) {
        moon_power += member.first;
        p_values.push_back(abs(member.second));
    }
    
    sort(p_values.begin(), p_values.end(), greater<long long>());
    
    long long current_power = sun_power;
    bool ritual_succeed = false;
    
    for(int i = 1; i <= p_values.size(); i++) {
        current_power += moon_power * i;
        
        if(current_power == sun_power) {
            ritual_succeed = true;
            cout << "Yes " << i << endl;
            break;
        }
    }
    
    if(!ritual_succeed) {
        cout << "No" << endl;
    }

    return 0;
}