#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int main() {
	int m;
	while (cin >> m) {
		if (m == 0) {
			break;
		}
		vector<P> data(m);
		cin >> data[0].first >> data[0].second;
		for (int i = 1; i < m; i++) {
			cin >> data[i].first >> data[i].second;
			data[i].first -= data[0].first;
			data[i].second -= data[0].second;
		}
		int n;
		cin >> n;
		set<P> star;
		P p;
		for (int i = 0; i < n; i++) {
			cin >> p.first >> p.second;
			star.insert(p);
		}
		set<P>::iterator it = star.begin();
		for (int i = 0; i < star.size(); i++) {
			bool hantei = true;
			for (int j = 1; j < data.size(); j++) {
				if (star.find(P((*it).first+data[j].first, (*it).second+data[j].second)) != star.end()) {
				} else {
					hantei = false;
					break;
				}
			}
			if (hantei) {
				cout << (*it).first-data[0].first << ' ' << (*it).second-data[0].second << endl;
				break;
			}
			it++;
		}
	} 
	return 0;
}