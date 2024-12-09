#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> skills(k);
    for (int i = 0; i < k; i++) {
        cin >> skills[i];
    }

    vector<pair<int, pair<int, int>>> improvements; // (type, (skill, value))
    for (int i = 0; i < n; i++) {
        int type, skill, value;
        cin >> type >> skill >> value;
        improvements.push_back({type, {skill, value}});
    }

    sort(improvements.begin(), improvements.end(), greater<pair<int, pair<int, int>>>()); // sort by type in descending order
    
    vector<int> result_indices;
    int total_improvements = 0;

    for (int i = 0; i < n; i++) {
        int type = improvements[i].first;
        int skill = improvements[i].second.first;
        int value = improvements[i].second.second;

        if (type == 1) { // assign
            skills[skill-1] = value;
            result_indices.push_back(i+1);
            total_improvements++;
        } else if (type == 2) { // add
            skills[skill-1] += value;
            result_indices.push_back(i+1);
            total_improvements++;
        } else if (type == 3) { // multiply
            skills[skill-1] *= value;
            result_indices.push_back(i+1);
            total_improvements++;
        }

        if (total_improvements == m) {
            break;
        }
    }

    cout << result_indices.size() << endl;
    for (int i = 0; i < result_indices.size(); i++) {
        cout << result_indices[i] << " ";
    }

    return 0;
}