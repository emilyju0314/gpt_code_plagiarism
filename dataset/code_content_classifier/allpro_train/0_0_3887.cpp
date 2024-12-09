#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

void query0(int x, deque<int>& sequence) {
    if(sequence.empty()) {
        sequence.push_back(x);
    } else {
        sequence.push_front(x);
    }
}

int query1(deque<int>& sequence) {
    int res;
    if(sequence.size() % 2 == 0) {
        res = sequence[sequence.size()/2 - 1];
        sequence.erase(sequence.begin() + sequence.size()/2 - 1);
    } else {
        res = sequence[sequence.size()/2];
        sequence.erase(sequence.begin() + sequence.size()/2);
    }
    return res;
}

int query2(const deque<int>& sequence) {
    int min_element = *min_element(sequence.begin(), sequence.begin() + (sequence.size() + 1) / 2);
    return min_element;
}

int query3(const deque<int>& sequence) {
    int min_element = *min_element(sequence.begin() + (sequence.size() + 1) / 2, sequence.end());
    return min_element;
}

int query4(int i, deque<int> sequence) {
    vector<int> min_elements;
    while(!sequence.empty()) {
        min_elements.push_back(query2(sequence));
        query1(sequence);
    }
    sort(min_elements.begin(), min_elements.end());
    return min_elements[i-1];
}

int query5(int i, deque<int> sequence) {
    vector<int> min_elements;
    while(!sequence.empty()) {
        min_elements.push_back(query3(sequence));
        query1(sequence);
    }
    sort(min_elements.begin(), min_elements.end());
    return min_elements[i-1];
}

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int query;
        cin >> query;
        deque<int> sequence;

        if(query == 0) {
            int x;
            cin >> x;
            query0(x, sequence);
        } else if(query == 1) {
            cout << query1(sequence) << endl;
        } else if(query == 2) {
            cout << query2(sequence) << endl;
        } else if(query == 3) {
            cout << query3(sequence) << endl;
        } else if(query == 4) {
            int x, y;
            cin >> x >> y;
            cout << query4(x, y, sequence) << endl;
        } else if(query == 5) {
            int x, y;
            cin >> x >> y;
            cout << query5(x, y, sequence) << endl;
        } else if(query == 6) {
            cout << *max_element(sequence.begin(), sequence.begin() + (sequence.size() + 1) / 2) << endl;
        } else if(query == 7) {
            cout << *max_element(sequence.begin() + (sequence.size() + 1) / 2, sequence.end()) << endl;
        } else if(query == 8) {
            int i, x;
            cin >> i >> x;
            // Implement query 8
        } else if(query == 9) {
            int i, x;
            cin >> i >> x;
            // Implement query 9
        }
    }

    cout << "end" << endl;

    return 0;
}